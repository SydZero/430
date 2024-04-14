#include <bits/stdc++.h>
using namespace std;

class graph{
public:
    struct node{
        int name;
        set<node*> adj;
        int d;
        int low;
        bool visited;
        node* parent;
        node(int name): name(name), d(-1), low(-1), visited(false), parent(this){}
    };

    node** nodes;
    int p;
    bool bridge;

    graph(int pinit) : p(pinit){
        nodes = new node*[p];
        for(int i = 0; i < p; i++){
            nodes[i] = new node(i);
        }
        bridge = false;
    }

    void add_edge(int a, int b){
        nodes[a]->adj.insert(nodes[b]);
        nodes[b]->adj.insert(nodes[a]);
    }

    void dfs_recurse(node* a){
        
        for(node* adj : a->adj){
            if(!adj->visited){
                adj->visited = true;
                adj->d = a->d + 1;
                adj->low = a->d + 1;
                adj->parent = a;
                dfs_recurse(adj);
                a->low = min(a->low, adj->low);
                if(adj->low > a->d){
                    bridge = true;
                }
            } else if(adj != a->parent){
                a->low = min(a->low, adj->d);
            }

        }
    }

    void dfs(){
        for(int i = 0; i < p; i++){
            if(!nodes[i]->visited){
                nodes[i]->visited = true;
                nodes[i]->d = 0;
                nodes[i]->low = 0;
                dfs_recurse(nodes[i]);
            }
        }

        // for(int i = 0; i < p; i++){
        //     cout << i << ": " << nodes[i]->low << " " << nodes[i]->d << endl;
        // }
    }
             
};

int main(){
    int p, c;

    while(cin >> p >> c){
        
        if(c == 0 && p == 0){
            break;
        }
        
        graph g = graph(p);
        for(int i = 0; i < c; i++){
            int x, y;
            cin >> x >> y;
            g.add_edge(x, y);
        }

        g.dfs();

        if(g.bridge){
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }


    return 0;
}