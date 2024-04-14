#include <bits/stdc++.h>
using namespace std;
struct node{
    string name;
    string spoken;
    set<string> understood;
    set<node*> speakto;
    set<node*> understands;
    int dfs;
    int low;
    bool processing;
    bool visited;
    
    node(istringstream& input): visited(false), dfs(INT32_MAX), low(INT32_MAX), processing(false){
        input >> name;
        string lang;
        input >> lang;
        spoken = lang;
        understood.insert(lang);
        while(input >> lang){
            understood.insert(lang);
        }
    }
};

class graph{
public:
    long long n;
    map<string, node*> nodes;
    int i;
    vector<vector<node*>> sccs;

    graph(long long n) : n(n), i(0){
        string line;
        getline(cin, line);
        for(long long i = 0; i < n; i++){
            getline(cin, line);
            istringstream strstrm(line);
            node* curr = new node(strstrm);
            // cout << curr->name << ": " ;
            // for(string l : curr->understood){
            //     cout << l << " ";
            // }
            // cout << endl;
            for(pair<string, node*> n : nodes){
                if(curr->understood.find(n.second->spoken) != curr->understood.end()){
                    n.second->speakto.insert(curr);
                    curr->understands.insert(n.second);
                }
                if(n.second->understood.find(curr->spoken) != n.second->understood.end()){
                    curr->speakto.insert(n.second);
                    n.second->understands.insert(curr);
                }
            }
            
            nodes.insert({curr->name, curr});
        }
    }
    
    void dfs_forward(node* n, stack<node*>& l){
        if(n->visited == false){
            n->visited = true;
            for(node* adj: n->speakto){
                dfs_forward(adj, l);
            }
            l.push(n);
        }
    }
    void dfs_back(node* n, vector<node*>& scc){
        if(n->visited == false){
            n->visited = true;
            for(node* adj: n->understands){
                dfs_back(adj, scc);
            }
            scc.push_back(n);
        }
    }

    void kosaraju(){
        stack<node*> s_forward;

        for(pair<string, node*> n : nodes){
            if(n.second->visited == false){
                dfs_forward(n.second, s_forward);
            }
        }

        for(pair<string, node*> n : nodes){
            n.second->visited = false;
        }
        
        while(!s_forward.empty()){
            node* curr = s_forward.top();
            s_forward.pop();
            if(curr->visited == false){
                vector<node*> scc;
                dfs_back(curr, scc);
                sccs.push_back(scc);
            }
        }
    }

    int num_remove(){
        size_t maxc = 0;
        for(int i = 0; i < sccs.size(); i++){
            maxc = max(maxc, sccs.at(i).size());
        }

        return n - maxc;
    }

    void print(){
        for(int i = 0; i < sccs.size(); i++){
            cout << i << ":" << endl;
            for(int j = 0; j < sccs.at(i).size(); j++){
                cout << sccs.at(i).at(j)->name << endl;
            }
        }

        // for(pair<string, node*> n : nodes){
        //     cout << n.second->name << ": ";
        //     for(node* adj : n.second->speakto){
        //         cout << adj->name << ", ";
        //     }
        //     cout << endl;
        // }
    }


};

int main(){
    long long n;
    cin >> n;

    graph g = graph(n);

    g.kosaraju();

    //g.print();

    cout << g.num_remove() << endl;

    return 0;
}