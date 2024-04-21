#include <bits/stdc++.h>
using namespace std;

struct node{
    int x;
    double y;
    bool inq;
    set<node*> adj;
    int time;
    bool visited;

    node(int x, int y): x(x), y(y), time(INT32_MAX), inq(false), visited(false){}

    void print(){
        cout << "(" << x << ", " << y << ")";
    }
};

class mycomp{
public:
    bool operator() (const node* p1, const node* p2) const{
        return p1->time > p2->time;
    }
};

class graph{
public:
    node* start;
    node* end;
    set<node*> stores;
    int curr;

    graph() {}

    void home(int x, int y){
        start = new node(x, y);
    }

    void endn(int x, int y){
        end = new node(x, y);
    }

    void add_store(int x, int y){
        stores.insert(new node(x, y));
    }

    void edges(){
        stores.insert(start);
        stores.insert(end);
        for(node* s : stores){
            for(node* j : stores){
                if(s == j){
                    continue;
                } else {
                    if(dist(s, j) <= 50 * 20){
                        s->adj.insert(j);
                        j->adj.insert(s);
                    }
                }
                
            }
        }
    }

    int dist(node* a, node*  b){
        return abs(a->x - b->x) + abs(a->y - b->y);
    }

    

    bool dfs(){
        stack<node*> q;
        q.push(start);
        
        while(!q.empty()) {
            node* a = q.top(); 
            q.pop();
            if (!a->visited) {
                a->visited = true;
                for(node* adj : a->adj) {
                    if(adj == end){
                        return true;
                    }
                    q.push(adj);
                }
            }
        }
        return false;
    }
};

int main(){
    int t, n;

    cin >> t;


    for(int i = 0; i < t; i++){
        cin >> n;
        int x, y;

        graph g = graph();
        cin >> x >> y;
        g.home(x, y);

        // cout << "home: " << x << ", " << y << endl;
        for(int j = 0; j < n; j++){
            cin >> x >> y;
            g.add_store(x, y);
            // cout << "store: " << x << ", " << y << endl;
        }
        cin >> x >> y;
        g.endn(x, y);
        // cout << "end: " << x << ", " << y << endl;

        g.edges();

        bool val = g.dfs();

        if(val){
            cout << "happy" << endl;
        } else {
            cout << "sad" << endl;
        }
        
    }


    
    return 0;
} 