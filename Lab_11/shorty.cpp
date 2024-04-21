#include <bits/stdc++.h>
using namespace std;

struct node{
    
    bool visited;
    bool inq;
    double dist;
    multimap<double, node*> adj;

    node(): dist(DBL_MIN), visited(false), inq(false){}

};

class mycomp{
public:
    bool operator() (const node* p1, const node* p2) const{
        return p1->dist > p2->dist;
    }
};

class graph{
public:
    
    node* start;
    node* end;
    vector<node*> cannons;
    
    int curr;

    graph(int n) {
        cout << n << endl;
        for(int i = 0; i < n; i++){
            cannons.push_back(new node());
        }
        cout << cannons.size() << endl;
    }

    void add_edge(int x, int y, double weight){
        cannons.at(x)->adj.insert({weight, cannons.at(x)});
        cannons.at(y)->adj.insert({weight, cannons.at(y)});
    }

    void shortest_path(){ 
        cout << "shortest_path" << endl;
        start->dist = -1;
        priority_queue<node*, vector<node*>,  mycomp> q;
        cout << cannons.size() << endl;
        for(node* v : cannons){
            q.push(v);
            v->inq = true;
        }
        cout << "hey" << endl;
        while(!q.empty()){
            node* curr = q.top();
            q.pop();
            
            curr->inq = false;
            for(pair<double, node*> adj : curr->adj){
                
                if(adj.second->inq){
                    double temp = -1 * abs(curr->dist * adj.first);

                    if(temp < adj.second->dist){
                        adj.second->dist = temp;
                        q.push(curr);
                        curr->inq = true;
                    }
                }
            }
        }
        cout << fixed << setprecision(6) << end->dist << endl;
    }      
};

int main(){
    int t, n, m;


    while(cin >> n >> m){
        if( m == 0 && n == 0){
            break;
        }

        graph g = graph(n);
        cout << "howdy" << endl;
        for(int j = 0; j < m; j++){
            int x, y;
            double w;
            cin >> x >> y >> w;
            
            g.add_edge(x, y, w);
        }

        g.shortest_path();
    }
    return 0;
} 