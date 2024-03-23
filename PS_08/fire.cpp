#include <bits/stdc++.h>
using namespace std;

class graph{
public:
    struct node{
        set<node*> adj;
        char name;
        int fire_num;
        int r;
        int c;
        int step;
        bool exit;

        node(char name, int r, int c) : name(name), r(r), c(c), fire_num(INT32_MAX), step(INT32_MAX), exit(false){}

        void print(){
            cout << "(" << r << ", " << c << "): step=" << step << " firenum=" << fire_num << endl;
        }
    };

    node*** nodes;
    long long rows;
    long long cols;
    pair<int, int> j_start;
    pair<int, int> f_start;
    int num_spaces;
    set<node*> exits;

    graph(long long rows, long long cols) : rows(rows), cols(cols), num_spaces(0){
        nodes = new node**[rows];
        
        for (long long r = 0; r < rows; r++){
            nodes[r] = new node*[cols];
            for (long long c = 0; c < cols; c++){
                char temp;
                int k = 0;
                cin >> temp;
                if(temp == 'J'){
                    j_start = {r, c};
                    nodes[r][c] = new node('.', r, c);
                    num_spaces++;
                } else if(temp == 'F'){
                    f_start = {r, c};
                    nodes[r][c] = new node('.', r, c);
                    num_spaces++;
                } else if(temp == '#'){
                    nodes[r][c] = new node('#', r, c);
                } else {
                    nodes[r][c] = new node('.', r, c);
                    num_spaces++;
                }
            }
        }

        for (long long r = 0; r < rows; r++){
            for (long long c = 0; c < cols; c++){
                if(nodes[r][c]->name == '.'){
                    if(r == rows - 1 || r == 0 || c == cols - 1 || c == 0){
                        nodes[r][c]->adj.insert(nullptr);
                        nodes[r][c]->exit = true;
                        exits.insert(nodes[r][c]);
                    }
                    if(r > 0 && nodes[r - 1][c]->name == '.'){
                        nodes[r][c]->adj.insert(nodes[r - 1][c]);
                    }
                    if(r < rows - 1 && nodes[r + 1][c]->name == '.'){
                        nodes[r][c]->adj.insert(nodes[r + 1][c]);
                    }
                    if(c > 0 && nodes[r][c - 1]->name == '.'){
                        nodes[r][c]->adj.insert(nodes[r][c - 1]);
                    }
                    if(c < cols - 1 && nodes[r][c + 1]->name == '.'){
                        nodes[r][c]->adj.insert(nodes[r][c + 1]);
                    }
                }
            }
        }

        queue<node*> q;
        q.push(nodes[f_start.first][f_start.second]);
        nodes[f_start.first][f_start.second]->fire_num = 0;
        while(!q.empty()) {
            node* a = q.front(); 
            q.pop();
            for(node* adj : a->adj){
                if(adj && adj->fire_num == INT32_MAX){
                    adj->fire_num = a->fire_num + 1;
                    q.push(adj);
                }
            }
        }

        q.push(nodes[j_start.first][j_start.second]);
        nodes[j_start.first][j_start.second]->step = 0;
        while(!q.empty()) {
            node* a = q.front(); 
            q.pop();
            for(node* adj : a->adj){
                if(adj && adj->step == INT32_MAX){
                    adj->step = a->step + 1;
                    q.push(adj);
                }
            }
        }
    }

    int bfs(){
        int mins = INT32_MAX;
        for(node* e : exits){
            if(e->step < e->fire_num){
                mins = min(e->step + 1, mins);
            }
        }
        return mins;
    }
};

int main(){
    long long rows, cols;
    cin >> rows >> cols;

    graph g = graph(rows, cols);

    int sol = g.bfs();

    if(sol != INT32_MAX){
        cout << sol << endl;
    } else {
        cout << "IMPOSSIBLE" << endl;
    }

    for (long long r = 0; r < rows; r++){
        for (long long c = 0; c < cols; c++){
            if(g.nodes[r][c]->name == '#' || g.nodes[r][c]->fire_num == INT32_MAX){
                cout << ".";
            } else {
                cout << g.nodes[r][c]->fire_num;
            }
        }
        cout << endl;
    }
    cout << "____________" << endl;

    for (long long r = 0; r < rows; r++){
        for (long long c = 0; c < cols; c++){
            if(g.nodes[r][c]->name == '#' || g.nodes[r][c]->step == INT32_MAX){
                cout << ".";
            } else {
                cout << g.nodes[r][c]->step;
            }
        }
        cout << endl;
    }

    return 0;
}