#include <bits/stdc++.h>
using namespace std;

class graph{
public:
    struct node{
        int name;
        set<node*> parent;
        bool picked_up;
        bool processing;

        node(int n) : name(n), picked_up(0), processing(0){}
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
        nodes[b]->parent.insert(nodes[a]);
    }

    bool dfs(node* init, stringstream &output) {
        if(init->processing == true){
            return false;
        }
        init->processing = true;
        for (node *par : init->parent){
            if(!par->picked_up && !dfs(par, output)){
                return false;
            }
        }

        init->processing = false;
        init->picked_up = true;
        output << init->name << endl;
        return true;
    }

    void pickup(){
        bool valid = true;
        stringstream output = stringstream();
        for (int i = 1; i < n; i++){
            // dfs(i, output);
            if (!nodes[i]->picked_up && !dfs(nodes[i], output)) {
                valid = false;
                break;
            }
        }

        if (!valid){
            cout << "IMPOSSIBLE" << endl;
            return;
        }

        string line;
        while (getline(output, line)){
            cout << line << endl;
        }
    }
};

int main()
{
    int n, m;
    cin >> n >> m;

    graph g = graph(n);

    for (int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;

        g.add_edge(a, b);
    }

    g.pickup();

    return 0;
}