#include <bits/stdc++.h>
using namespace std;

class graph{
public: 
    struct node{
        string name;
        set<node*> children;
        bool visited;
        char who;
        node() : name(""), visited(false), who('0'){}
    };

    long long n;
    node** nodes;
    map<string, node*> node_map;
    set<node*> hank;
    set<node*> jessie;


    graph(long long ogn): n(ogn){
        nodes = new node*[n];
        for(int i = 1; i <= n; i++){
            nodes[i] = new node();
            cin >> nodes[i]->name;
            node_map[nodes[i]->name] = nodes[i];
        }
    }

    void add_edge(string a, string b){
        node* anode = node_map[a];
        node* bnode = node_map[b];
        anode->children.insert(bnode);
        bnode->children.insert(anode);
    }

    bool bfshelper(node* curr){
        char person = 'H';
        queue<node*> q;
               
        q.push(curr);
        q.push(nullptr);
        // cout << "searching: " << curr->name << endl;
        while(!q.empty()){
            curr = q.front();
            q.pop();
            
            if(curr == nullptr){
                // cout << "Break: " << q.size() << endl;
                if(q.size() != 0){
                    q.push(nullptr);
                    if(person == 'H'){
                        person = 'J';
                    } else {
                        person = 'H';
                    }
                }
                continue;
            }
            // cout << curr->name << " ";         
            if(curr->who != '0'){
                if(curr->who != person){
                    // cout << curr->who << "!=" << person << endl;
                    return false;
                }
            } else {
                curr->who = person;
                if(person == 'H'){
                    hank.insert(curr);
                } else {
                    jessie.insert(curr);
                }
            }
            for(node* child : curr->children){
                if(child->who == '0'){
                    q.push(child);
                } else if(child->who == person){
                    // cout << child->who << "==" << person << endl;
                    return false;
                } 
            }
        }
        // cout << "end search" << endl;
        return true;
    }

    bool bfs(){
        for(int i = 1; i <= n; i++){
            if(nodes[i]->who == '0'){
                if(!bfshelper(nodes[i])){
                    return false;
                }
            }
        }
        return true;
    }

    void print(){
        for(node* item: hank){
            cout << item->name << " ";
        }
        cout << endl;
        for(node* item: jessie){
            cout << item->name << " ";
        }

        cout << endl;
    }

};


int main(){
    int n, m;
    cin >> n;
    graph g = graph(n);
    cin >> m;

    for(int i = 0; i < m; i++){
        string item1, item2;
        cin >> item1 >> item2;
        g.add_edge(item1, item2);
    }
    
     
    // for(int i = 0; i < n; i++){
    //     cout << g.nodes[i + 1]->name << ":" << g.nodes[i + 1]->children.size() << " ";
    // }
    // cout << endl;

    if(g.bfs()){
        g.print();
    } else {
        cout << "impossible" << endl;
    }

    return 0;
}