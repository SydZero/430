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
    bool visited;

    node(int name): name(name), medical(false), max_people(INT32_MAX), visited(false){}
};

struct road{
    int a;
    int b;
    int p;
    int t;

    road(int a, int b, int p, int t): a(a), b(b), p(p), t(t){}
};

class graph{
public:
    int n;
    int i, g, s, m;
    vector<node*> facilities;
    vector<road*> roads;
    vector<node*> nodes;

    node* src;

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

    void clear_visited(){
        for(node* n : nodes){
            n->visited = false;
        }
    }

    bool bfs(){
        queue<node*> q;
        q.push(src);
        src->visited = true;
        src->parent = nullptr;

        while(!q.empty()){
            node* a = q.front();
            q.pop();

            for(node* adj : a->adj){
                if(!adj->visited){
                    if(adj->medical){
                        return true;
                    }
                    q.push(adj);
                    adj->visited = true;
                }
            }
        }
        return false;
    }

    long max_flow(){
        long sum = 0;
        while(bfs()){
            
        }
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