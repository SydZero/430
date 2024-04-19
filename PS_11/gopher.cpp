#include <bits/stdc++.h>
using namespace std;
//max flow
struct hole;
struct gopher{
    double x;
    double y;
    set<hole*> holes;

    gopher(double x, double y): x(x), y(y){}
};

struct hole{
    double x;
    double y;
    set<gopher*> gophers;
    bool visited;
    gopher* g;

    hole(double x, double y): x(x), y(y), visited(false), g(nullptr){}
};

class graph{
public:
    long n;
    long m;
    long s;
    long v;
    vector<gopher*> gs;
    vector<hole*> hs;
    

    graph(long n, long m, long s, long v): n(n), m(m), s(s), v(v){}

    void add_gopher(double x, double y){
        gs.push_back(new gopher(x, y));
    }

    void add_hole(double x, double y){
        hs.push_back(new hole(x, y));
    }

    void add_edge(gopher* g, hole* h){
        double dist = sqrt(pow(g->x - h->x, 2) + pow(g->y - h->y, 2));
        if(dist / v <= s){
            g->holes.insert(h);
            h->gophers.insert(g);
        }
    }

    void clear_visited(){
        for(hole* h : hs){
            h->visited = false;
        }
    }

    bool bp_helper(gopher* g){
        for(hole* h: g->holes){
            if(!h->visited){
                h->visited = true;
                if(h->g == nullptr || bp_helper(h->g)){
                    h->g = g;
                    return true;
                }
            }
        }
        return false;
    }

    long bipartite(){
        long sum = 0;
        for (long g = 0; g < gs.size(); g++){
            clear_visited();
            if(bp_helper(gs.at(g))){
                sum++;
            }
        }
        return sum;
    }
};

int main(){
    long n, m, s, v;

    while(cin >> n >> m >> s >> v){
        graph g = graph(n, m, s, v);
    
        double x, y;
        for(int i = 0; i < n; i++){
            cin >> x >> y;
            g.add_gopher(x, y);
        }

        for(int i = 0; i < m; i++){
            cin >> x >> y;
            g.add_hole(x, y);
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                g.add_edge(g.gs.at(i), g.hs.at(j));
            }
        }

        cout << n - g.bipartite() << endl;
    }

    

    
    return 0;
} 