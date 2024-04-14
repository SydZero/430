#include <bits/stdc++.h>
using namespace std;

class graph{
public:
    struct node{
        
        bool covered;
        node(): covered(false){}
    };

    node*** nodes;
    int rows;
    int cols;
    int total;
  

    graph(int rows, int cols) : rows(rows), cols(cols), total(0){
        //cout << "rows" << rows << endl;
        nodes = new node**[rows];
        for (int r = 0; r < rows; r++){
            nodes[r] = new node*[cols];
            for (int c = 0; c < cols; c++){
                nodes[r][c] = new node();
            }
        }
    }

    int numsides(int x, int y){

        if(nodes[y][x]->covered){
            return 0;
        }
        nodes[y][x]->covered = true;
        int count = 0;

        bool top = false;
        bool bottom = false;
        bool left = false;
        bool right = false;

        bool ul = false;
        bool ur = false;
        bool bl = false;
        bool br = false;

        // cout << "hey: " << y-1 << " " << rows << endl;
        //top && bottom
        if((y == 0 || nodes[y-1][x]->covered)){
            top = true;
        }
        // cout << "FLAG" << endl;
        //left
        if(x == 0 || nodes[y][x-1]->covered){
            left = true;
        }
        // cout << "FLAG" << endl;
        if(y + 1 == rows || nodes[y + 1][x]->covered){
            bottom = true;
        }

        if(x + 1 == cols|| nodes[y][x+1]->covered){
            right = true;
        }
        
        if(x > 0 && y < rows - 1 && nodes[y+1][x-1]->covered){
            bl = true;
        }

        if(x < cols - 1 && y > 0 && nodes[y-1][x+1]->covered){
            ur = true;
        }

        if(x < cols - 1 && y < rows - 1 && nodes[y+1][x+1]->covered){
            br = true;
        }

        if(x > 0 && y > 0 && nodes[y-1][x-1]->covered){
            ul = true;
        }

        if(top && bottom && left && right){
            return -1;
        }

        if((top && bottom && !left && !right) || (!top && !bottom && left && right)){
            return 1;
        }

        if(!top && !bottom && !left && !right){
            return 0;
        }

        if(ul && !top && ur){
            return 1;
        }

        if(ur && !right && br){
            return 1;
        }

        if(ul && !left && bl){
            return 1;
        }

        if(bl && !bottom && br){
            return 1;
        }

        return 0;
        
    }

    void draw(int x1, int y1, int x2, int y2){
        // cout << "drawing: " << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
        if(x1 == x2){
            int x = x1 - 1;
            for(int y = y1 - 1; y <= y2 -1; y++){
                // cout << x << " " << y << endl;
                int num_side = numsides(x, y);
                total += num_side;
            }
        } else if(y1 == y2){
            int y = y1 - 1;
            for(int x = x1 - 1; x <= x2 - 1; x++){
                // cout << x << " " << y << endl;
                int num_side = numsides(x, y);
                total += num_side;
            }
        }
        cout << total << endl;
    }
};

int main(){
    int n, m, q;      
    cin >> n >> m >> q;
    
    graph g = graph(m, n);

    for(int i = 0; i < q; i++){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        g.draw(x1, y1, x2, y2);
    }

    return 0;
}
