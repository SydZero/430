#include <bits/stdc++.h>
using namespace std;

class graph{
public:
    struct node{
        int name;
        node* parent;

        node(int name): parent(this), name(name){}
    };

    struct edge{
        node* start;
        node* end;
        double length;

        edge(node* startn, node* endn, int l): start(startn), end(endn), length(l){}
    };

    class mycomp{
    public:
        bool operator() (const edge* p1, const edge* p2) const{
            return p1->length < p2->length;
        }
    };

    long long M;
    long long C;
    vector<node*> nodes;
    vector<edge*> edges;

    graph(long long M, long long C) : M(M), C(C){
        for(int i = 0; i < C; i++){
            nodes.push_back(new node(i));
        }
    }

    void add_edge(int i, int j, int D){
        edges.push_back(new edge(nodes.at(i), nodes.at(j), D));
    }

    node* parent(node* p){
        if(p != p->parent){
            node* prent = parent(p->parent);
            p->parent = prent;
            return prent;
        }
        return p->parent;
    }

    void kruskals(){ 
        int ans = 1; 
        
        // vector<int> final_edges;
        sort(edges.begin(), edges.end(), mycomp());
        for (edge* e : edges) { 
            int w = e->length; 
            
            node* para = parent(e->start);
            node* parb = parent(e->end);
            
            if (para != parb) { 
                ans += w + 1;
                parb->parent = para;
            } 
        } 

        if(ans <= M){
            cout << "yes" << endl;
        } else {
            cout << "no" << endl;
        }

    }      
};


int main(){
    int n;
    cin >> n;
    for(int q = 0; q < n; q++){
        int M, C;
        cin >> M >> C;

        graph g = graph(M, C);

        for(int k = 0; k < (C * (C-1)) / 2; k++){
            int i, j, D;
            cin >> i >> j >> D;
            g.add_edge(i, j, D);
        }

        g.kruskals();
    }

    


    return 0;
}