#include <bits/stdc++.h>
using namespace std;

struct node{
    node* parent;
    long long name;
    long long owes;
    long long sum;

    node(){
        parent = this;
        name = -1;
        owes = 0;
        sum = 0;
    }
};

node* parent(node* p){
    if(p == p->parent){
        return p;
    }
    p->parent = parent(p->parent);
    return p->parent;
}

class DisjointedSet{
public:
    vector<node*> friends;
    

    DisjointedSet(): friends(0){

    }

    void insert(long long owes){
        node* temp = new node();
        temp->name = friends.size();
        temp->owes = owes;
        temp->sum = owes;
        friends.push_back(temp);
    }

    void node_union(long long p, long long q){
        node* parp = parent(friends[p]->parent);
        node* parq = parent(friends[q]->parent);
        if(parp == parq){
            return;
        }
        parq->parent = parp;
        parp->sum += parq->sum;
    }

    void sums_of_parents(){
        for(long long i = 0; i < friends.size(); i++){
            if(friends.at(i)->parent == friends.at(i)){
                if(friends.at(i)->sum != 0){
                    cout << "IMPOSSIBLE" << endl;
                    return;
                }
            }
        }
        cout << "POSSIBLE" << endl;
    }


};

int main(){
    long long n, m;

    cin >> n >> m;
    DisjointedSet ds = DisjointedSet();

    for (long long i = 0; i < n; i++){
        long long o;
        cin >> o;
        ds.insert(o);
    }

    for (long long i = 0; i < m; i++){
        long long f1, f2;
        cin >> f1 >> f2;
        ds.node_union(f1, f2);
    }

    ds.sums_of_parents();
    
    return 0;
}
