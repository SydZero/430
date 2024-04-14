#include <bits/stdc++.h>
using namespace std;

class graph{
public:
    struct node{
        string name;
        bool changed;
        bool visited;
        set<node*> adj;
        
        node(string name): name(name){}
    };

    long long n;
    map<string, node*> nodes;

    graph(long long n) : n(n){
        for(int i = 0; i < n; i++){
            string line;
            getline(cin, line);
            istringstream strstrm(line);
            string file;

            strstrm >> file;
            file = file.substr(0, file.size() - 1);

            if(nodes.find(file) == nodes.end()){
                nodes.insert({file, new node(file)});
            } 

            node* curr = nodes[file];
            string temp;
            while(strstrm >> temp){
                if(nodes.find(temp) == nodes.end()){
                    nodes.insert({temp, new node(temp)});
                }

                nodes[temp]->adj.insert(curr);
            }

        }
    }

    void dependencies(string file){
        auto fileNode = nodes.find(file);

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
    }    
};

int main(){
    int n;
    cin >> n;

    graph g = graph(n);

    return 0;
}