#include <bits/stdc++.h>
using namespace std;

vector<tuple<int, int, int>> out;
struct node{
    node* parent;
    int i;
    int count;
    node(int i): i(i), parent(this), count(1){}
};

node* parent(node* p){
    if(p->parent != p){
        p->parent = parent(p->parent);
    }
    return p->parent;
}

bool union_node(node* p, node* q){
    node* parp = parent(p);
    node* parq = parent(q);

    if(parp == parq){
        return false;
    }
    parp->parent = parq;
    parq->count += parp->count;
    return true;
}

int main(){
    int n;
    cin >> n;
    node* tree[n + 1];
    multimap<int, int> people;
    for(int i = 1; i <= n; i++){
        tree[i] = new node(i);
        int m;
        cin >> m;
        for(int j = 0; j < m; j++){
            int k;
            cin >> k;
            people.insert({k, i});
        }
    }

    for(auto i = people.begin(); i != people.end(); i++){
        auto j = i;
        j++;
        if(j != people.end() && i->first == j->first){
            if(union_node(tree[i->second], tree[j->second])){
                out.push_back({i->second, j->second, i->first});
            }
            
        }
    }


    if(parent(tree[1])->count == n){
        for(int i = 0; i < out.size(); i++){
            cout << get<0>(out.at(i)) << " " << get<1>(out.at(i)) << " " << get<2>(out.at(i)) << endl;
        }
    } else {
        cout << "impossible" << endl;
    }
      
    return 0;
}
