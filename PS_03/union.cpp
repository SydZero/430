#include <bits/stdc++.h>
using namespace std;

struct node{
    node* parent;
    long long value;
    long long sum;
    long long count;

    node(long long t): parent(this), value(t), sum(t), count(1){
    }
};


//fuckit redo

class full_tree{
    private:
        node** tree;
        long long n;

    public:
        full_tree(long long n): n(n){
            tree = new node*[n + 1];

            for(long long i = 0; i <= n; i++){
                tree[i] = new node(i);
            }
        }

        node* parent(node* p){
            if(p != p->parent){
                p->parent->sum -= p->sum;
                p->parent->count -= p->count;
                p->parent = parent(p->parent);
            }
            return p->parent;
        }
        
        void node_union(long long pi, long long qi){
            node* p = tree[pi];
            node* q = tree[qi];

            node* parp = parent(p);
            node* parq = parent(q);

            if(parp != parq){

            }
        }

        void move_node(long long  pi, long long  qi){
            node* p = tree[pi];
            node* q = tree[qi];

            node* parp = parent(p);
            node* parq = parent(q);

            if(parp != parq){
                
            }
        }

        void num_sum(long long pi){
            node* p = tree[pi];

            node* parp = parent(p);

            cout << parp->count << " " << parp->sum << endl;
        }

        node* at(long long p){
            return tree[p];
        }

        void print_set(set<node*> vals){
            if(vals.empty()){
                return;
            }
            cout << "[";
            for(node* str: vals){
                cout << str->value << " " ;
            }
            cout << "]";
        }

        void print_node(node* n){
            cout << n->value << ": {" << n->sum << ", " << n->count;
            cout << "} ";
        }


        void print_tree(){
            if(true){
                cout << "________________" << endl;
                for(long long i = 1; i <= n; i++){
                    print_node(tree[i]);
                    cout << " -> ";
                    print_node(tree[i]->parent);
                    cout << endl;
                }
                cout << "________________" << endl;
            }
        }


};


int main(){
    long long n, m;
    cin >> n >> m;

    full_tree FT = full_tree(n);

    
    long long ins, p, q;
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
        FT.print_tree();
    }

    

    return 0;
}