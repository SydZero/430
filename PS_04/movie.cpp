#include <bits/stdc++.h>
using namespace std;

struct node{
    long long movie;
    bool val;
    long long sum;
    long long last_seen;


    node(){
        movie = 0;
        val = false;
        sum = 0;
        last_seen = 0;
    }
    node(long long m, bool v, long long s, long long ls){
        movie = m;
        val = v;
        sum = s;
        last_seen = ls;
    }
};

long long lsone(long long n){
    return (n & (-n));
}

class fenwick{

    public: 
        long long n;
        long long m;
        long long r;
        node* tree;
        long long curr;

        fenwick(long long m, long long r): n(m + r), m(m), r(r){
            tree = new node[n + 1];
            curr =  r;
            for(long long i = 1; i <= m; i++){
                tree[r + i] = node(i, true, 0, r + i);
            }
        }

        void add_movies(long long i){
            
            tree[i + r].last_seen = i + r;

            long long change = 1;

            i = i + r;
            
            while(i <= n){
                tree[i].sum += change;
                i = i + lsone(i);
            }
        }
    
        void on_top(long long i){
            long long ls = tree[i + r].last_seen;
            
            tree[i + r].last_seen = curr;
            tree[ls].val = false;
            tree[curr].movie = i;
            tree[curr].val = true;
            i = curr;
            curr--;


            while(i <= n){
                tree[i].sum += 1;
                i = i + lsone(i);
            }
            while(ls <= n){
                tree[ls].sum -= 1;
                ls = ls + lsone(ls);
            }

        }
        
        long long sum(long long i){
            long long sum = 0;
            long long ind = tree[r + i].last_seen;
            ind--;
            //cout << "sum from " << 1 << " to " << ind << endl;
            while(ind > 0){
                sum += tree[ind].sum;
                ind = ind - lsone(ind);
            }
            return sum;
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
                cout << tree[i].movie;                
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
    long long n, m, r;
    
    cin >> n;

    for(long long i = 0; i < n; i++){
        cin >> m >> r;
        
        fenwick fen(m, r);
        for(int j = 1; j <= m; j++){
            fen.add_movies(j);
        }
        //fen.print();

        for(int j = 0; j < r; j++){
            long long move;
            cin >> move;
            cout << fen.sum(move) << " ";
            fen.on_top(move);
            //fen.print();
        }
        cout << endl;
    }
      
    return 0;
}
