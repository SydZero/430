#include <bits/stdc++.h>
using namespace std;
struct node{
    string name;
    node* parent;
    long long size;
    set<string> spoken;
    set<string> understood;
    bool print_visited;
    
    node(istringstream& input): parent(this), size(1), print_visited(false){
        input >> name;
        string lang;
        input >> lang;
        spoken.insert(lang);
        understood.insert(lang);
        while(input >> lang){
            understood.insert(lang);
        }
    }
};

class graph{
public:
    long long w, h;
    node*** nodes;

    graph(long long w, long long h) : w(w), h(h){
        nodes = new node**[h];
        for(long long i = 0; i < w; i++){
            nodes[r] = new node*[w];
        }
    }

    node* parent(node* p){
        if(p->parent != p){
            p->parent = parent(p->parent);
        }
        return p->parent;
    }

};

int main(){
    long long n;
    cin >> n;

    graph g = graph(n);

    // for(node* p : g.nodes){ 
    //     cout << p->name << endl;
    // }
    g.find_unions();
    // g.print();

    return 0;
}