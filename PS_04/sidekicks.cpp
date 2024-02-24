#include <bits/stdc++.h>
using namespace std;

struct node{
    long long val;
    long long total[7];

    node(){
        val = 0;
        total[0] = 0;
        total[1] = 0;
        total[2] = 0;
        total[3] = 0;
        total[4] = 0;
        total[5] = 0;
        total[6] = 0;
    }
};

long long lsone(long long n){
    return (n & (-n));
}

class fenwick{
    public: 
        node* p;
        long long n;
        long long* v;

        fenwick(long long n): n(n){
            p = new node[n + 1];
            v = new long long[7];
            for(long long i = 0; i <= n; i++){
                p[i] = node();
            }
        }
    
        void flip(long long k, long long pi){
            long long index = k;
            long long og = p[k].val;
            // cout << index << ": " << og << "->" << p[pi].val << endl;
            p[k].val = pi;
            
            while(index <= n){
                p[index].total[og]--;
                p[index].total[pi]++;
                index = index + lsone(index);
            }
        }

        void insert(long long i, long long pi){
            long long index = i;

            p[i].val = pi;
            
            while(index <= n){
                p[index].total[pi]++;
                index = index + lsone(index);
            }
        }

        void change_val(long long pi, long long vi){
            v[pi] = vi;
        }
        
        long long sum1(long long i){
            long long sum = 0;
            while(i > 0){
                sum += p[i].total[1] * v[1];
                sum += p[i].total[2] * v[2];
                sum += p[i].total[3] * v[3];
                sum += p[i].total[4] * v[4];
                sum += p[i].total[5] * v[5];
                sum += p[i].total[6] * v[6];
                i = i - lsone(i);
            }
            return sum;
        }

        void sum(long long l, long long r){
            long long suml = sum1(l - 1);
            long long sumr = sum1(r);
            
            cout << (sumr - suml) << endl;
        }

        void print(){
            cout << "________________________" << endl;
            for(long long i = 1; i <= n; i++){
                cout << p[i].val << " ";
            }
            cout << endl;

            for(long long i = 1; i <= 6; i++){
                cout << v[i] << " ";
            }

            cout << endl;
            for(long long i = 1; i <= n; i++){
                cout << i << ": ";
                cout << p[i].total[1] << " ";
                cout << p[i].total[2] << " ";
                cout << p[i].total[3] << " ";
                cout << p[i].total[4] << " ";
                cout << p[i].total[5] << " ";
                cout << p[i].total[6] << endl;
            }

            
            cout << "________________________" << endl;

        }

        void print(long long l, long long r){
            cout << "________________________" << endl;

            for(long long i = 1; i <= n; i++){
                if(i == l){
                    cout << "|";
                }
                cout << p[i].val << " ";
                if(i == r){
                    cout << "|";
                } 
            }
            cout << endl;
            cout << "________________________" << endl;

        }

};

int main(){
    long long n, q;
    
    cin >> n >> q;

    fenwick fen = fenwick(n);

    cin >> fen.v[1] >> fen.v[2] >> fen.v[3] >> fen.v[4] >> fen.v[5] >> fen.v[6];

    string str;
    cin >> str;

    for(long long i = 0; i < n; i++){
        fen.insert(i + 1, str.at(i) - '0');
    }
    
    for(long long i = 0; i < q; i++){
        long long ins;
        cin >> ins;
        if(ins == 1){
            long long ki, pi;
            cin >> ki >> pi;
            fen.flip(ki, pi);
        } else if(ins == 2){
            long long pi, v;
            cin >> pi >> v;
            fen.change_val(pi, v);
        } else if(ins == 3){
            long long li, ri;
            cin >> li >> ri;
            fen.sum(li, ri);
        }
        //fen.print();
    }

    

    return 0;
}
