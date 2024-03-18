#include <bits/stdc++.h>
using namespace std;

class graph{
public: 
    struct node{
        int name;
        set<node*> children;
        set<node*> parents;
        bool picked_up;

        node():name(-1){}
    };

    long long n;
    node** nodes;
    map<string, node*> node_map;
    set<pair<node*, node*>> edges;


    graph(long long ogn): n(ogn + 1){
        nodes = new node*[n];
        for(int i = 1; i <= n; i++){
            nodes[i] = new node();
            nodes[i]->name = i;
            nodes[i]->picked_up = false;
        }
    }

    void add_edge(int a, int b){
        nodes[a]->children.insert(nodes[b]);
        nodes[b]->parents.insert(nodes[a]);
        edges.insert({nodes[a], nodes[b]});
    }

    bool dfs(node* init, stringstream& output){
        if(init->picked_up == true && init->parents.size() != 0){
            return false;
        }
        for(node* parent: init->parents){
            if(!parent->picked_up && !dfs(parent, output)){
                return false;
            }
        }
        if(!init->picked_up){
            output << init->name << endl;
            init->picked_up = true;
            return true;
        }
        return false;
    }

    void pickup(){
        bool valid = true;
        stringstream output = stringstream();
        for(int i = 1; i <= n; i++){
            if(nodes[i]->picked_up == false && !dfs(nodes[i], output)){
                valid = false;
                break;
            }
        }

        if(!valid){
            cout << "IMPOSSIBLE" << endl;
            return;
        }

        string line;
        while(output >> line){
            cout << line << endl;
        }
        
    }
};

int main(){
    int n, m;
    cin >> n >> m;

    graph g = graph(n);

    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;

        g.add_edge(a, b);
    }

    g.pickup();

    return 0;
}