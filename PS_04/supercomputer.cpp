#include <bits/stdc++.h>
using namespace std;

struct node{
    node* parent;
    bool val;
    long long sum;
    long long lower_bound;
    long long upper_bound;

    node(){
        val = false;
        sum = 0;
        lower_bound = 0;
        upper_bound = 0;
    }
};

long long lsone(long long n){
    // cout << n << "->" << (n & (-n)) << endl;;
    return (n & (-n));
}

class fenwick{

    public: 
        long long n;
        node* tree;


        fenwick(long long n): n(n){
            tree = new node[n + 1];
            for(long long i = 0; i <= n; i++){
                tree[i] = node();
            }
        }
    
        void flip(long long i){
            tree[i].val = !tree[i].val;

            long long change = 0;
            

            while(i <= n){
                // cout << "updating: " << i << endl;
                tree[i].sum += change;
                i = i + lsone(i);
                // cout << "Next i: " << i << endl;
            }
        }
        
        long long sum1(long long i){
            long long sum = 0;
            while(i > 0){
                sum += tree[i].sum;
                i = i - lsone(i);
            }
            return sum;
        }

        void sum(long long l, long long r){
            //print(l, r);
            long long suml = sum1(l - 1);
            long long sumr = sum1(r);
            
            cout << (sumr - suml) << endl;
        }

        void print(){
            cout << "________________________" << endl;
            for(int i = 1; i <= n; i++){
                if(tree[i].val){
                    cout << 1;
                } else {
                    cout << 0;
                }   
            }
            cout << endl;
            for(int i = 1; i <= n; i++){
                cout << tree[i].sum;                
            }
            cout << endl;
            cout << "________________________" << endl;

        }

        void print(long long l, long long r){
            cout << "________________________" << endl;

            for(int i = 1; i <= n; i++){
                if(i == l){
                    cout << "|";
                }
                if(tree[i].val){
                    cout << 1;
                } else {
                    cout << 0;
                }
                if(i == r){
                    cout << "|";
                } 
            }
            cout << endl;
            for(int i = 1; i <= n; i++){
                cout << tree[i].sum;                
            }
            cout << endl;
            cout << "________________________" << endl;

        }

};

int main(){
    long long n, k;
    
    cin >> n >> k;
    
    fenwick fen = fenwick(n);

    for(long long i = 0; i < k; i++){
        char ins;
        cin >> ins;
        if(ins == 'F'){
            long long i;
            cin >> i;
            fen.flip(i);

        } else if(ins == 'C'){
            long long l, r, count;
            cin >> l >> r;
            fen.sum(l, r);
        }
        //fen.print();
    }
    
    return 0;
}
