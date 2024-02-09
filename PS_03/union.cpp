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

class full_tree{
    private:
        node** tree;
        long long n;

    public:
        full_tree(long long n): n(n){
            tree = new node*[n + 1];

            //create n+1 nodes so no indexing changes later
            for(long long i = 0; i <= n; i++){
                tree[i] = new node(i);
            }
        }

        //literally just want logic to work before path compression
        node* parent(node* p){
            if(p != p->parent){
                node* newrt = parent(p->parent);
                // print_node(p);
                // cout << " ";
                // print_node(p->parent);

                if(p->parent != newrt){
                    p->parent->sum -= p->sum;
                    p->parent->count -= p->count;
                }

                // cout << " ";
                // print_node(p->parent);
                // cout << endl;
                p->parent = newrt;
                return p->parent;
            }
            return p->parent;
        }

        //used for move node, changes all nodes with parent p to have parent q
        void new_parents(node* p, node* q){
            if(!q || p == q){
                return;
            }
            for(long long i = 1; i <= n; i++){
                if(tree[i]->parent == p){
                    tree[i]->parent = q;
                    //q already has its own info stored
                    if(tree[i] != q){
                        q->sum += tree[i]->sum;
                        q->count += tree[i]->count;
                    }
                }
            }
        }
        
        void node_union(long long pi, long long qi){
            node* p = tree[pi];
            node* q = tree[qi];

            node* parp = parent(p);
            node* parq = parent(q);

            if(parp != parq){
                parp->parent = parq;
                
                parq->count += parp->count;
                parq->sum += parp->sum;
            }
        }

        void move_node(long long  pi, long long  qi){
            node* p = tree[pi];
            node* q = tree[qi];

            node* parp = parent(p);
            node* parq = parent(q);

            
            if(parp != parq){
                node* new_parent = nullptr;
                if(parp != p){
                    //if !root
                    new_parent = parp;
                    new_parent->parent = parp;
                    new_parent->sum -= p->sum;
                    new_parent->count -= p->count;
                } else {
                    //if root
                    for(long long i = 1; i <= n; i++){
                        if(tree[i]->parent == p){
                            new_parent = tree[i];
                            break;
                        }
                    }
                }

                p->parent = parq;
                p->sum = p->value;
                p->count = 1;

                if(new_parent){
                    new_parents(p, new_parent);
                }

                parq->count += p->count;
                parq->sum += p->sum;
            }

            

        }

        void num_sum(long long pi){
            node* p = tree[pi];

            node* parp = parent(p);

            cout << parp->count << " " << parp->sum << endl;
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
            cout << n->value << ": {" << n->sum << ", " << n->count << "}";
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
            // FT.print_tree();
        }
    }
    

    return 0;
}