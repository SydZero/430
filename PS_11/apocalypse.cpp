#include <bits/stdc++.h>
using namespace std;
//max flow
struct road;
struct node{
    int name;
    set<node*> adj;
    set<road*> out;
    int max_people;
    bool medical;

    node(int name): name(name), medical(false), max_people(INT32_MAX){}
};

struct road{
    int a;
    int b;
    int p;
    int t;

    road(int a, int b, int p, int t): a(a), b(b), p(p), t(t){}
};

// class mycomp{
// public:
//     bool operator() (const node* p1, const node* p2) const{
//         return p1->time > p2->time;
//     }
// };

class graph{
public:
    int n;
    int i, g, s, m;
    vector<int> facilities;
    vector<road*> roads;
    vector<node*> nodes;

    graph(int n, int i, int g, int s, int m): n(n), i(i), g(g), s(s), m(m){
        nodes.push_back(new node(0));
        for(int i = 1; i <= n; i++){
            nodes.push_back(new node(i));
        }
    }

    void add_road(int a, int b, int p, int t){
        roads.push_back(new road(a, b, p, t));
        nodes.at(a)->out.insert(roads.at(roads.size()-1));
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