#include <bits/stdc++.h>
using namespace std;

class graph{
public:
    struct node{
        set<node*> adj;
        char name;
        int r;
        int c;
        int d;
        int low;

        node(int val, int r, int c) : name(val), r(r), c(c){}

        void print(){
            cout << "(" << r << ", " << c << ") " << " adjsize=" << adj.size() << endl;
        }
    };

    node*** nodes;
    int rows;
    int cols;
    int rings;
    queue<node*> q;

    graph(int rows, int cols) : rows(rows), cols(cols), rings(0){
        nodes = new node**[rows];
        
        for (int r = 0; r < rows; r++){
            nodes[r] = new node*[cols];
            for (int c = 0; c < cols; c++){
                int temp;
                cin >> temp;
                nodes[r][c] = new node(temp, r, c);
            }
        }

        for (int r = 0; r < rows; r++){
            for (int c = 0; c < cols; c++){
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

    }
};

int main(){
    int m, n;      
    cin >> m >> n;
    
    graph g = graph(m, n);


    return 0;
}
