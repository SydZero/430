#include <bits/stdc++.h>
using namespace std;

struct node{
    int x;
    int y;
    char c;
    int dist;
    bool inq;

    node(double x, double y, char c): x(x), y(y), c(c), inq(false){}
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
    node*** nodes;
    int curr;
    int rows, cols;
    

    graph(int rows, int cols) : rows(rows), cols(cols){
        nodes = new node**[rows];
        for (int r = 0; r < rows; r++){
            nodes[r] = new node*[cols];
            for (int c = 0; c < cols; c++){
                char temp;
                cin >> temp;
                nodes[r][c] = new node(c, r, temp);
                if(temp == 'D' && (r == rows - 1 || r == 0 || c == 0 || c == cols -1)){
                    end = nodes[r][c];
                }
            }
        }
        int x, y;
        cin >> x >> y;
        start = nodes[x][y];
    }

    void shortest_path(){ 
        priority_queue<node*, vector<node*>,  mycomp> q;
        for (int r = 0; r < rows; r++){
            for (int c = 0; c < cols; c++){
                q.push(nodes[r][c]);
                nodes[r][c]->inq = true;
            }
        }
        while(!q.empty()){
            node* curr = q.top();
            q.pop();
            curr->inq = false;
            if((y == 0 || nodes[y-1][x]->inq)){
                if(temp < adj->dist){
                    adj->dist = temp;
                    q.push(curr);
                    curr->inq = true;
                }
            }
            //left
            if(x == 0 || nodes[y][x-1]->inq){
                if(temp < adj->dist){
                    adj->dist = temp;
                    q.push(curr);
                    curr->inq = true;
                }
            }

            //down
            if(y == rows - 1 || nodes[y + 1][x]->inq){
                if(temp < adj->dist){
                    adj->dist = temp;
                    q.push(curr);
                    curr->inq = true;
                }
            }

            //right
            if(x == cols - 1 || nodes[y][x+1]->inq){
                if(temp < adj->dist){
                    adj->dist = temp;
                    q.push(curr);
                    curr->inq = true;
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