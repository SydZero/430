#include <bits/stdc++.h>
using namespace std;

struct node{
    node* parent;
    long long value;
    long long sum;
    long long count;
    set<node*> children;

    node(long long t): parent(this), value(t), sum(t), count(1){
    }
};

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
    cout << n->value << ": {" << n->sum << ", " << n->count << ", ";
    print_set(n->children);
    cout << "} ";
}


void print_tree(node* tree[], long long n){
    if(true){
        cout << "________________" << endl;
        for(long long i = 0; i < n; i++){
            print_node(tree[i]);
            cout << " -> ";
            print_node(tree[i]->parent);
            cout << endl;
        }
        cout << "________________" << endl;
    }
}

node* parent(node* p){
    if(p != p->parent){
        node* prent = parent(p->parent);
        p->parent = prent;
        p->count = 1;
        p->sum = p->value;
        return prent;
    }
    return p;
}

void node_union(node* p, node* q){
    node* parp = parent(p);
    node* parq = parent(q);

    if(parp == parq){
        return;
    }

    parp->parent = parq;

    parq->count += parp->count;
    parq->sum += parp->sum;
    parq->children.insert(parp->children.begin(), parp->children.end());
    parq->children.insert(parp);
    //cout << parq->count << endl;
}

void move_node(node* p, node* q){
    node* parp = parent(p);
    node* parq = parent(q);
    
    if(parp == parq){
        return;
    } 

    node* new_parent = nullptr;

    if(parp == p){
        if(!p->children.empty()){
            new_parent = *(p->children.begin());
            p->children.erase(new_parent);
            new_parent->parent = new_parent;
            new_parent->count = p->count - 1;
            new_parent->sum = p->sum - p->value;
        }
    } else {
        
        new_parent = parp;
        new_parent->children.erase(p);
        new_parent->count--;
        new_parent->sum -= p->value;
    }


    if(new_parent != nullptr){
        for(auto i = p->children.begin(); i != p->children.end(); i++){
            (*i)->parent = new_parent;
            (*i)->children.clear();
            new_parent->children.insert(*i);
        }
    }

    p->children.clear();
    p->count = 1;
    p->sum = p->value; 
    p->parent = parq;

    parq->count++;
    parq->sum += p->value;
    parq->children.insert(p);   
}

void num_sum(node* p){
    node* par = parent(p);
    cout << par->count << " " << par->sum << endl;
}

int main(){
    long long n, m;
    cin >> n >> m;

    node* tree[n];

    for(long long i = 0; i < n; i++){
        tree[i] = new node(i + 1);
    }
    //print_tree(tree, n);
    long long ins, p, q;
    for(long long i = 0; i < m; i++){
        cin >> ins;
        if(ins == 1){
            cin >> p >> q;
            node_union(tree[p - 1], tree[q - 1]);
        } else if(ins == 2){
            cin >> p >> q;
            move_node(tree[p - 1], tree[q - 1]);
        } else if(ins == 3){
            cin >> p;
            num_sum(tree[p - 1]);
        }
        print_tree(tree, n);
    }

    

    return 0;
}