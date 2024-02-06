#include <bits/stdc++.h>
using namespace std;

struct node{
    node* parent;
    long long value;
    long long size;

    node(int t): parent(this), value(t), size(1){
    }
};

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

    parq->size += parp->size;
   
    //cout << parq->count << endl;
}

int main(){
    int n;
    cin >> n;

    long long m;
    map<long long, node*> ingredients;
    set<set<node*>> cauldrens;

    for(long long i = 0; i < n; i++){
        cin >> m;
        long long c;
        bool make = true;
        for(long long j = 0; j < m; j++){
            cin >> c;
            if(ingredients[c]){

            } else {
                
            }
        }
    }

    return 0;
}
