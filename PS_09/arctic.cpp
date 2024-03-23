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
    set<pair<node*, node*>> edges;

    graph(long long p) : p(p){
        nodes = new node*[p];
        
        for (long long i = 0; i < p; i++){
            nodes[i] = new node();
        }
    }

    void add_edge(int a, int b){
        nodes[b]->adj.insert(nodes[a]);
        nodes[a]->adj.insert(nodes[b]);
        edges.insert({nodes[min(a, b)], nodes[max(a, b)]});
    }
             
};

int main(){
    long long p, c;
    while(true){
        cin >> p >> c;

        if(p == 0 && c == 0){
            break;
        }

        graph g = graph(p);

        for(int i = 0; i < c; i++){
            int a, b;
            cin >> a >> b;
            g.add_edge(a, b);
        }
    }


    return 0;
}