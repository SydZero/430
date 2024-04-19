#include <bits/stdc++.h>
using namespace std;

struct in;
struct out;

struct node{
    long r;
    long c;
    long num;
    long r_num;
    multimap<long, node*> adj;
    bool visited;
    bool in;
    bool sink;

    node(long r, long c, long num, bool in): r(r), c(c), num(num), r_num(num), visited(false), in(in), sink(false){}
};


class graph{
public:
    long rows;
    long cols;

    vector<vector<pair<node*, node*>>> nodes;  

    node* source;

    graph(long rows, long cols): rows(rows), cols(cols){
        nodes = vector<vector<pair<node*, node*>>>(rows);
        for(int r = 0; r < rows; r++){
            nodes.at(r) = vector<pair<node*, node*>>(cols);
            for(int c = 0; c < cols; c++){
                long num;
                cin >> num;
                nodes.at(r).at(c).first = new node(r, c, num, true);
                nodes.at(r).at(c).second = new node(r, c, num, false);
                nodes.at(r).at(c).first->adj.insert({nodes.at(r).at(c).second->num, nodes.at(r).at(c).second});
            }
        }

        for(int r = 0; r < rows; r++){
            for(int c = 0; c < cols; c++){
                if(r == 0 || c == 0 || r == rows-1 || c == cols - 1){
                    nodes.at(r).at(c).second->sink;
                }
                for(int i = -1; i <= 1; i++){
                    for(int j = -1; j <= 1; j++){
                        if(r + i < 0 || c + j < 0 || r + i >= rows || c + j >= cols){
                            continue;
                        }
                        nodes.at(r).at(c).second->adj.insert({INT32_MAX, nodes.at(r + i).at(c + j).second});
                    }
                }
            }
        }
    }

    void castle(long r, long c){
        source = nodes.at(r).at(c).second;
    }

    bool bfs(){
        queue<node*> q;
        q.push(source);

        while (!q.empty()) {
            node* u = q.front();
            q.pop();
    
            for (pair<long, node*> v : u->adj) {
                if(!v.second->visited && v.first > 0) {
                    if(v.second->sink) {
                        return true;
                    }
                    q.push(v.second);
                    v.second->visited = true;
                }
            }
        }
    }

    bool max_flow(){
        long max_flow = 0;
        while(bfs()){
            long p_flow = INT32_MAX;
            
        }
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