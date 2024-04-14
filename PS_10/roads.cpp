#include <bits/stdc++.h>
using namespace std;

struct node{
    int name;
    bool visited;
    set<node*> goesto;
    set<node*> comesfrom;
    node(int name): name(name), visited(false){}
};

class graph{
public:
    vector<node*> nodes;
    vector<pair<node*, node*>> roads;
    int curr;

    graph(int m) {
        for(int i = 0; i < m; i++){
            nodes.push_back(new node(i));
        }
    }

    void add_road(int a, int b){
        nodes.at(a)->goesto.insert(nodes.at(b));
        nodes.at(b)->comesfrom.insert(nodes.at(a));
        roads.push_back({nodes.at(a), nodes.at(b)});
    }

    void dfs_forward(node* init) {
        init->visited = true;
        // cout << init->name << "->";
        for (node *par : init->goesto){
            if(!par->visited){
                dfs_forward(par);
            }
        }
    }

    void dfs_back(node* init) {
        init->visited = true;
        // cout << init->name << "->";
        for (node *par : init->comesfrom){
            if(!par->visited){
                dfs_back(par);
            }
        }
    }

    bool all_visited() {
        bool all = true;
        for (node* p : nodes){
            // cout << p->visited << " ";
            if(!p->visited){
                all = false;
            }
            p->visited = false;
        }
        // cout << endl;
        return all;
    }

    bool iv_help(){
        bool forward = false;
        bool back = false;

        dfs_forward(nodes.at(0));
        // cout << endl;
        if(!all_visited()){
            // cout << "forward-bad" << endl;
            return false;
        }
        dfs_back(nodes.at(0));
        // cout << endl;
        if(!all_visited()){
            // cout << "back-bad" << endl;
            return false;
        }
        return true;
    }

    void is_valid(){
        if(iv_help()){
            cout << "valid" << endl;
            return;
        } else {
            for(pair<node*, node*> r : roads){
                r.first->goesto.erase(r.second);
                r.second->goesto.insert(r.first);
                r.second->comesfrom.erase(r.first);
                r.first->comesfrom.insert(r.second);
                if(iv_help()){
                    cout << r.first->name << " " << r.second->name << endl;
                    return;
                }
                r.first->goesto.insert(r.second);
                r.second->goesto.erase(r.first);
                r.second->comesfrom.insert(r.first);
                r.first->comesfrom.erase(r.second);

            }
        }
        cout << "invalid" << endl;
    }
};

int main(){
    int m, n;
    int c = 1;
    while(cin >> m >> n){
        graph g = graph(m);
        for(int i = 0; i < n; i++){
            int a, b;
            cin >> a >> b;
            g.add_road(a, b);
        }
        cout << "Case " << c << ": ";
        g.is_valid();
        c++;
    }

    return 0;
} 