#include <bits/stdc++.h>
using namespace std;

void print_set(set<long long> vals){
    if(vals.empty()){
        return;
    }
    for(long long str: vals){
        cout << str << " " ;
    }
}

class full_tree{
    private:
        set<long long>* sets;
        long long* tree;
        long long* sum;
        long long n;

    public:
        full_tree(long long n): n(n){
            sets = new set<long long>[n + 1];
            tree = new long long[n + 1];
            sum = new long long[n+1];

            for(long long i = 0; i <= n; i++){
                sets[i].insert(i);
                tree[i] = i;
                sum[i] = i;
            }
        }
        
        void node_union(long long pi, long long qi){
            long long p = tree[pi];
            long long q = tree[qi];

            if(sets[p].size() > sets[q].size()){
                long long temp = p;
                p = q;
                q = temp;
            }
            
            if(p != q){
                sets[q].insert(sets[p].begin(), sets[p].end());
                for(long long num: sets[p]){
                    tree[num] = q;
                }
                sets[p].clear();
                sum[q] += sum[p];
                sum[p] = 0;
                // tree[p] = q;
            }
        }

        void move_node(long long  pi, long long  qi){
            long long p = tree[pi];
            long long q = tree[qi];
            
            if(p != q){
                sum[p] -= pi;
                sum[q] += pi;
                sets[p].erase(pi);
                sets[q].insert(pi);
                tree[pi] = q;
            }
        }

        void num_sum(long long pi){
            long long p = tree[pi];

            cout << sets[p].size() << " " << sum[p] << endl;
        }

        void print_tree(){
            cout << "______________" << endl;
            for(long long i = 1; i <= n && i < 20; i++){
                cout << i << ": sum=" << sum[i] << "  in_set=" << tree[i] <<"   ";
                print_set(sets[i]);
                cout << endl;
            }
            cout << "______________" << endl;
        }

        ~full_tree(){
            delete[] sets;
            delete[] tree;
            delete[] sum;
        }
};


int main(){
    long long n, m;
    
    long long ins, p, q;
    while(cin >> n >>  m){
        full_tree FT = full_tree(n);
        for(long long i = 0; i < m; i++){
            cin >> ins;
            if(ins == 1){
                cin >> p >> q;
                FT.node_union(p, q);
            } else if(ins == 2){
                cin >> p >> q;
                FT.move_node(p, q);
            } else if(ins == 3){
                cin >> p;
                FT.num_sum(p);
            }
            //FT.print_tree();
        }
    }
    

    return 0;
}