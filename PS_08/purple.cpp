#include <bits/stdc++.h>
using namespace std;

class graph{
public:
    struct node{
        int name;
        set<node*> adj;
        bool picked_up;
        bool processing;
        int dist;

        node(int n) : name(n), picked_up(0), processing(0), dist(INT32_MAX){}
    };

    long long n;
    node**nodes;
    map<string, node*> node_map;
    set<pair<node*, node*>> edges;

    graph(long long ogn) : n(ogn + 1){
        nodes = new node*[n];
        for (int i = 1; i < n; i++){
            nodes[i] = new node(i);
        }
    }

    void add_edge(int a, int b){
        nodes[b]->adj.insert(nodes[a]);
        nodes[a]->adj.insert(nodes[b]);
    }


    int bfs(){
        queue<node*> q;
        nodes[1]->dist = 0;
        q.push(nodes[1]);
        while(!q.empty()) {
            node* a = q.front(); 
            q.pop();
            
            for(node* adj : a->adj) {
                if(adj->dist > a->dist + 1){
                    adj->dist = a->dist + 1;
                    q.push(adj);
                }
                
            }
        }
        return nodes[n - 1]->dist;
    }

};

int main(){
    int n, m;
    cin >> n >> m;

    graph g = graph(n);

    for (int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;

        g.add_edge(a, b);
    }

    cout << g.bfs() - 1 << endl;

    return 0;
}