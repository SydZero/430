#include <bits/stdc++.h>
using namespace std;

class graph{
public:
    struct node{
        set<node*> adj;
        node(){}
    };

    node** nodes;
    long long p;
    set<pair<int, int>> edges;

    graph(long long pinit) : p(pinit + 1){
        nodes = new node*[p];
        for(int i = 1; i <= p; i++){
            nodes[i] = new node();
        }
    }

    void add_edge(int a, int b){
        nodes[a]->adj.insert(nodes[b]);
        nodes[b]->adj.insert(nodes[a]);
        edges.insert({a, b});
    }
             
};

int main(){
    int n, m;

    cin >> n >> m;

    graph g = graph(n);

    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        g.add_edge(x, y);
    }
    
    return 0;
}