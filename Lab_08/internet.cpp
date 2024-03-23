#include <bits/stdc++.h>
using namespace std;

class graph{
public:
    struct node{
        int name;
        node* parent;

        node(int n) : name(n), parent(this){}
    };

    node* parent(node* curr){
        //cout << "    " << curr->name << " " << curr->parent->name << endl;
        if(curr->parent == curr){
            return curr;
        }
        curr->parent = parent(curr->parent);
        return curr->parent;
    }

    long long n;
    node** nodes;

    graph(long long ogn) : n(ogn + 1){
        nodes = new node*[n];
        for (int i = 1; i < n; i++){
            nodes[i] = new node(i);
            
        }
    }

    void add_edge(int a, int b){
        node* parb = parent(nodes[b]);
        node* para = parent(nodes[a]);

        parb->parent = para;
    }

    void pickup(){
        bool connected = true;
        node* par = parent(nodes[1]);
        for (int i = 2; i < n; i++){
            //cout << par->name << " " << parent(nodes[i])->name << endl;
            if(par != parent(nodes[i])){
                connected = false;
                cout << i << endl;
            }
        }

        if (connected){
            cout << "Connected" << endl;
            return;
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