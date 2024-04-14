#include <bits/stdc++.h>
using namespace std;

class graph{
public:
    struct node{
        node* parent;
        int name;
        int x;
        int y;
        node(int name, int x, int y): parent(this), name(name), x(x), y(y){}
    };

    struct edge{
        node* start;
        node* end;
        double length;

        edge(node* startn, node* endn, int l): start(startn), end(endn), length(l){}
    };

    long long s;
    long long p;
    vector<node*> nodes;
    vector<edge*> edges;

    graph(long long s, long long p) : p(p), s(s){}

    void add_outpost(int a, int b){
        node* temp = new node(nodes.size(), a, b);
        nodes.push_back(temp);
        for(int i = 0; i < nodes.size() - 1; i++){
            edges.push_back(new edge(nodes[i], nodes[nodes.size() - 1], dist(nodes[i], nodes[nodes.size() - 1])));
        }
    }

    double dist(node* a, node* b){
        return sqrt(pow(a->x - b->x, 2) + pow(a->y - b->y, 2));
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
        int ans = 0; 
        vector<int> final_edges;
        sort(edges.begin(), edges.end());
        for (edge*  e : edges) { 
            int w = e->length; 
            
            node* para = parent(e->start);
            node* parb = parent(e->end);
            
            if (para != parb) { 
                ans += w;
                parb->parent = para;
                final_edges.push_back(w);
            } 
        } 
        sort(final_edges.begin(), final_edges.end(), less<int>());
        
        // for(double edge: final_edges){
        //     cout << sqrt(edge) << endl;
        // }

        cout << std::fixed << setprecision(2) << final_edges.at(final_edges.size() - s) << endl; 
    }      
};

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int s, p;
        cin >> s >> p;

        graph g = graph(s, p);

        for(int j = 0; j < p; j++){
            int x, y;
            cin >> x >> y;
            g.add_outpost(x, y);
        }

        g.kruskals();
    }

    


    return 0;
}