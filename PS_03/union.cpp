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
}

void move_node(node* p, node* q){
    node* parp = parent(p);
    node* parq = parent(q);
    
    if(parp == parq){
        return;
    } 

    node* new_rt = nullptr;

    if(parp == p){
        if(!p->children.empty()){
            new_rt = *(p->children.begin());
            p->children.erase(new_rt);
            new_rt->parent = new_rt;
            new_rt->count = p->count - 1;
            new_rt->sum = p->sum - p->value;
        }
    } else {
        new_rt = parp;
        node* curr = p->parent;
        node* next;
        while(curr != parp){
            next = curr->parent;
            curr->children.clear();
            curr->count = 1;
            curr->sum -= curr->value;
            curr->parent = parp;
            curr = next;
        }
        new_rt->children.erase(p);
        new_rt->count--;
        new_rt->sum -= p->value;
    }

    if(new_rt){
        for(auto i = p->children.begin(); i != p->children.end(); i++){
            (*i)->parent = new_rt;
            (*i)->children.erase(new_rt);
            new_rt->children.insert(*i);
        }
        p->children.clear();
    }

    p->parent = parq;
    p->count = 1;
    p->sum = p->value; 

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
        //print_tree(tree, n);
    }

    

    return 0;
}
