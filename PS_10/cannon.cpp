#include <bits/stdc++.h>
using namespace std;

struct node{
    double x;
    double y;
    bool cannon;
    bool inq;
    set<node*> adj;
    double time;

    node(double x, double y, bool cannon): x(x), y(y), cannon(cannon), time(DBL_MAX), inq(false){}

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
    vector<node*> cannons;
    int curr;

    graph(double ax, double ay, double bx, double by, int n) {
        start = new node(ax, ay, false);
        end = new node(bx, by, false);
        cannons = vector<node*>(n + 2);
        curr = 2;
        cannons.at(0) = start;
        cannons.at(1) = end;
        start->adj.insert(end);
        end->adj.insert(start);
    }

    void add_cannon(double x, double y){
        cannons.at(curr) = new node(x, y, true);
        for(int i = 0; i < curr; i++){
            cannons.at(i)->adj.insert(cannons.at(curr));
            cannons.at(curr)->adj.insert(cannons.at(i));
        }
        curr++;
    }

    double dist(node* a, node*  b){
        return sqrt(pow(a->x - b->x, 2) + pow(a->y - b->y, 2));
    }

    double time(node* a, node*  b){
        double distance = dist(a, b);
        if(a->cannon){
            if(distance > 50){
                return 2 + ((distance - 50) / 5);
            }
            return min(2 + ((50 - distance) / 5), distance / 5);
        }
        return distance / 5;
        
    }

    void shortest_path(){ 
        start->time = 0;
        priority_queue<node*, vector<node*>,  mycomp> q;
        for(node* v : cannons){
            q.push(v);
            v->inq = true;
        }
        
        while(!q.empty()){
            node* curr = q.top();
            q.pop();
            curr->print();
            cout << ": time-" << curr->time << endl;
            curr->inq = false;
            for(node* adj : curr->adj){
                if(adj->inq){
                    double temp = curr->time + time(curr, adj);
                    cout << "   ";
                    adj->print();
                    cout << ": " << temp << " " << adj->time << endl;
                    if(temp < adj->time){
                        adj->time = temp;
                        q.push(curr);
                        curr->inq = true;
                    }
                }
            }
        }
        cout << fixed << setprecision(6) << end->time << endl;
    }      
};

int main(){
    double ax, ay, bx, by;
    int n;
    cin >> ax >> ay >> bx >> by >> n;

    graph g = graph(ax, ay, bx, by, n);

    for(int i = 0; i < n; i++){
        double x, y;
        cin >> x >> y;
        g.add_cannon(x, y);
    }

    g.shortest_path();

    return 0;
} 