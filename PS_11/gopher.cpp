#include <bits/stdc++.h>
using namespace std;
//max flow
struct hole;
struct gopher{
    double x;
    double y;

    gopher(double x, double y): x(x), y(y){}
};

struct hole{
    double x;
    double y;

    hole(double x, double y): x(x), y(y){}
};

class graph{
public:
    int n;
    int m;
    vector<int> facilities;
    vector<gopher*> gs;
    vector<hole*> hs;

    graph(int n, int m): n(n), m(m){}

    void add_gopher(double x, double y){
        roads.push_back(new road(a, b, p, t));
        nodes.at(a)->out.insert(roads.at(roads.size()-1));
    }
    void add_hole(double x, double y){
        hs.push_back(new hole(a, b, p, t));
    }

    void bfshelper(node* curr){
        queue<node*> q; 
        q.push(curr);

        while(!q.empty()){
            curr = q.front();
            q.pop();
            for(road* r : curr->out){
                node* next = nodes.at(r->b);
                next->max_people = min(curr->max_people, next->max_people);
                if(!next->medical){
                    q.push(next);
                }
            }
        }
    }

    void max_flow(){

    }

};

int main(){
    int t;
    cin >> t;

    for(int k = 0; k < t; k++){
        int n;
        cin >> n;
        
        int i, g, s, m;
        graph gra = graph(n, i, g, s, m);
        cin >> i >> g >> s >> m;
        for(int j = 0; j < m; j++){
            int x;
            cin >> x;
            gra.nodes.at(x)->medical = true;
            gra.facilities.push_back(x);
        }
        int r;
        cin >> r;
        for(int j = 0; j < r; j++){
            int a, b, p, t;
            cin >> a >> b >> p >> t;
            gra.add_road(a, b, p, t);
        }
        gra.max_flow();
    }

    return 0;
} 