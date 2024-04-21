#include <bits/stdc++.h>
using namespace std;

struct edge;

struct node{
    long r;
    long c;
    long num;
    long level;
    
    set<edge*> adj;
    
    node(long r, long c, long num, bool in): r(r), c(c), num(num), level(-1){}
};

struct edge{
    node* to;
    node* from;
    long flow;
    long cap;
    edge* op;

    edge(node* to, node* from, long flow):to(to), from(from), flow(0), cap(flow){}
};

class graph{
public:
    long rows;
    long cols;

    vector<vector<pair<node*, node*>>> nodes;  

    vector<edge*> edges;
    node* source;
    node* sink;

    graph(long rows, long cols): rows(rows), cols(cols){
        sink = new node(-1, -1, -1000, false);
        nodes = vector<vector<pair<node*, node*>>>(rows);
        for(int r = 0; r < rows; r++){
            nodes.at(r) = vector<pair<node*, node*>>(cols);
            for(int c = 0; c < cols; c++){
                long num;
                cin >> num;
                nodes.at(r).at(c).first = new node(r, c, num, true);
                nodes.at(r).at(c).second = new node(r, c, num, false);
                add_edge(nodes.at(r).at(c).first, nodes.at(r).at(c).second, num);
            }
        }
        vector<int> x = {-1, 0, 1, 0};
        vector<int> y = {0, -1, 0, 1};

        for(int r = 0; r < rows; r++){
            for(int c = 0; c < cols; c++){
                if(r == 0 || c == 0 || r == rows-1 || c == cols - 1){
                    add_edge(nodes.at(r).at(c).second, sink, LONG_MAX);
                }
                for(int i = 0; i < x.size(); i++){
                    if(r + y.at(i) < 0 || c + x.at(i) < 0 || r + y.at(i) >= rows || c + x.at(i) >= cols){
                        continue;
                    }
                    add_edge(nodes.at(r).at(c).second, nodes.at(r + y.at(i)).at(c + x.at(i)).second, LONG_MAX);
                    add_edge(nodes.at(r + y.at(i)).at(c + x.at(i)).second, nodes.at(r).at(c).second, LONG_MAX);
                }
            }
        }
    }


    void add_edge(node* a, node* b, long cap){
        edge* e = new edge(b, a, cap);
        edge* eprime = new edge(a, b, 0);
        e->op = eprime;
        eprime->op = e;
        edges.push_back(e);
        edges.push_back(eprime);
        a->adj.insert(e);
       
        b->adj.insert(eprime);
    }

    void castle(long r, long c){
        source = nodes.at(r).at(c).second;
    }

    bool bfs(){

        for(vector<pair<node*, node*>>& v1 : nodes){
            for(pair<node*, node*>& p : v1){
                p.first->level = -1;
                p.second->level = -1;
            }
        }
        cout << "bfs_flow" << endl;
        source->level = 0;

        queue<node*> q;
        q.push(source);
        while(!q.empty()){
            node* u = q.front();
            q.pop();
            for(edge* e : u->adj){
                if(e->to->level < 0 && e->flow < e->cap){
                    e->to->level = u->level + 1;
                    q.push(e->to);
                }
            }
        }
        if(source->level == -1){
            return false;
        }
        return true;
    }

    long send_flow(node* u, long flow){
        cout << "send_flow: (" << u->r << ", " << u->c << "): " << flow << endl;
        if(u == sink){
            cout << "found sink" << endl;
            return flow;
        }

        for(edge* e : u->adj){
            if(e->to->level == u->level + 1 && e->flow < e->cap){
                cout << "edge deats: " << e->flow << " " << e->cap << endl;
                long curr_flow = min(flow, e->cap - e->flow);
                long temp_flow = send_flow(e->to, curr_flow);
                cout << e->flow << " " << curr_flow << " " << temp_flow << endl;;
                if(temp_flow > 0){
                    e->flow += temp_flow;
                    e->op->flow -= temp_flow;
                    return temp_flow;
                }
            }   
        }
        return 0;
    }

    bool max_flow(){
        cout << "max_flow" << endl;
        long total = 0;

        while(bfs()){
            long flow = send_flow(source, 1000);
            while(flow != 0){
                total += flow;
                flow = send_flow(source, 1000);
            }

        }
        return total;
    }
};

int main(){
    long R, C, r, c;

    cin >> R >> C;
    graph g = graph(R, C);
    cin >> r >> c;
    g.castle(r, c);
    
    cout << g.max_flow() << endl;
    
    return 0;
} 