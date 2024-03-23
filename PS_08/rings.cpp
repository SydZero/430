#include <bits/stdc++.h>
using namespace std;

class graph{
public:
    struct node{
        set<node*> adj;
        char name;
        int ring;
        int r;
        int c;

        node(char namey, int r, int c) : name(namey), r(r), c(c){
            if(name == 'T'){
                ring = 99;
            } else {
                ring = 0;
            }
        }

        void print(){
            cout << "(" << r << ", " << c << "): ring=" << ring << " adjsize=" << adj.size() << endl;
        }
    };

    node*** nodes;
    int rows;
    int cols;
    int rings;
    queue<node*> q;

    graph(int rows, int cols) : rows(rows), cols(cols){
        nodes = new node**[rows];
        
        for (int r = 0; r < rows; r++){
            nodes[r] = new node*[cols];
            for (int c = 0; c < cols; c++){
                char temp;
                cin >> temp;
                if(temp == 'T'){
                    nodes[r][c] = new node('T', r, c);
                } else {
                    nodes[r][c] = new node('.', r, c);
                    q.push(nodes[r][c]);
                }
            }
        }

        for (int r = 0; r < rows; r++){
            for (int c = 0; c < cols; c++){
                
                if(r == rows - 1 || r == 0 || c == cols - 1 || c == 0){
                    nodes[r][c]->ring = min(1, nodes[r][c]->ring);
                    q.push(nodes[r][c]);
                }
                if(r > 0 && nodes[r - 1][c]->name == 'T'){
                    nodes[r][c]->adj.insert(nodes[r - 1][c]);
                }
                if(r < rows - 1 && nodes[r + 1][c]->name == 'T'){
                    nodes[r][c]->adj.insert(nodes[r + 1][c]);
                }
                if(c > 0 && nodes[r][c - 1]->name == 'T'){
                    nodes[r][c]->adj.insert(nodes[r][c - 1]);
                }
                if(c < cols - 1 && nodes[r][c + 1]->name == 'T'){
                    nodes[r][c]->adj.insert(nodes[r][c + 1]);
                }
                //nodes[r][c]->print();
            }
        }

        while(!q.empty()){
            node* a = q.front(); 
            q.pop();
            rings = max(rings, a->ring);
            //a->print();
            for(node* adj : a->adj){
                // cout << "    " ;
                // adj->print();
                if(adj && adj->ring > a->ring + 1){
                    adj->ring = a->ring + 1;
                    q.push(adj);
                }
            }
        }

    }

    void print(){
        string leading = "";
        if(rings < 10){
            leading = "";
        } else {
            leading = ".";
        }

        for (int r = 0; r < rows; r++){
            for (int c = 0; c < cols; c++){
                if (nodes[r][c]->name == 'T'){
                    if (nodes[r][c]->ring < 10){
                        cout << leading << "." << nodes[r][c]->ring;
                    } else {
                        cout << leading << nodes[r][c]->ring;
                    }  
                } else {
                    cout << leading << "..";
                }
            }
            cout << endl;
        }
    }
};

int main(){
    int m, n;      
    cin >> m >> n;
    
    graph g = graph(m, n);

    g.print();

    return 0;
}
