#include <bits/stdc++.h>
using namespace std;

long long n, k;

void print_board(char** board){
    cout << "___________________" << endl;
    for(int r = 0; r < n; r++){
        for(int c = 0; c < n; c++){
            cout << board[r][c] << " ";
        }
        cout << endl;
    }
    cout << "___________________" << endl;
}

struct ship{
    int x;
    int y;
    int size;
    bool horizontal;
    ship(int y, int x, int size, bool horizontal): x(x), y(y), size(size), horizontal(horizontal){}
};

class board{
public:
    char** b;
    vector<pair<int, int>> hits;
    vector<int> sizes;
    stack<ship> current_ships;

    board(): hits(0), sizes(0){
        stack<ship> current_ships;
        b = new char*[n];
        for (long long r = 0; r < n; r++){
            b[r] = new char[n];
            for (long long c = 0; c < n; c++){
                cin >> b[r][c];
                if(b[r][c] == 'O'){
                    hits.push_back({r, c});
                    b[r][c] = '.';
                }
            }
        }
    }
    bool hits_good(){
        for(int i = 0; i < hits.size(); i++){
            if(b[hits.at(i).first][hits.at(i).second] != 'O'){
                return false;
            }
        }
        return true;
    }

    void remove_ship(){
        ship curr = current_ships.top();
        current_ships.pop();
        
        if(!curr.horizontal){
            for(int r = curr.y; r < curr.y + curr.size; r++){
                //cout << "   " << r << " " << curr.x << " = " << b[r][curr.x];
                b[r][curr.x] = 'b';
                //cout << "->" << b[r][curr.x] << endl;
            }
        } else {
            for(int c = curr.x; c < curr.x + curr.size; c++){
                b[curr.y][c] = 'b';
            }
        }
        //cout << "Removing: " << curr.size << " " << curr.y << " " << curr.x << " " << curr.horizontal << endl;
        //print_board(b);
    }

    bool place_horiz(long long s, long long r0, long long c0){
        if(c0 + s > n){
            return false;
        }
        for(int c = c0; c < c0 + s; c++){
            if(b[r0][c] == 'O' || b[r0][c] == 'X'){
                return false;
            }
        }
        for(int c = c0; c < c0 + s; c++){
            b[r0][c] = 'O';
        }
        ship sh = ship(r0, c0, s, true);
        current_ships.push(sh);
        return true;
    }

    bool place_vert(long long s, long long r0, long long c0){
        if(r0 + s > n){
            return false;
        }
        
        for(int r = r0; r < r0 + s; r++){
            if(b[r][c0] == 'O' || b[r][c0] == 'X'){
                return false;
            }
        }
        for(int r = r0; r < r0 + s; r++){
            b[r][c0] = 'O';
        }
        ship sh = ship(r0, c0, s, false);
        current_ships.push(sh);
        return true;
    }

    long long place_final(long long s, long long r0, long long c0){
        int sum = 0;
        if(s == 1){
            if(b[r0][c0] == 'O' || b[r0][c0] == 'X'){
                return 0;
            }
            b[r0][c0] = 'O';
            //print_board(b);
            if(hits_good()){
                b[r0][c0] = '.';
                return 1;
            }
            b[r0][c0] = '.';
            return 0;
        } else {
            bool found = true;
            if(c0 + s <= n){
                if(place_horiz(s, r0, c0)){
                    if(hits_good()){
                        sum += 1;
                    }
                    //print_board(b);
                    remove_ship();
                }
            }
            if(r0 + s <= n){
                if(place_vert(s, r0, c0)){
                    if(hits_good()){
                        sum += 1;
                    }
                    //print_board(b);
                    remove_ship();
                }
            }    
            return sum;
        }
    }

    int num_combos(long long i){
        int sum = 0;
        if(b == nullptr){
            return 0;
        }
        //print_board(b);
        for(int r = 0; r < n; r++){
            for(int c = 0; c < n; c++){
                if(b[r][c] == 'X' || b[r][c] == 'O'){
                    continue;
                }
                //cout << "place " << sizes.at(i) << "(" << i << ") at " << r << " " << c << endl;
                if(i == sizes.size() - 1){
                    sum += place_final(sizes.at(i), r, c);
                } else {
                    if(sizes.at(i) == 1){
                        if(place_vert(sizes.at(i), r, c)){
                            sum += num_combos(i + 1);
                            remove_ship();
                        }
                    } else {
                        if(r + sizes.at(i) <= n){
                            if(place_vert(sizes.at(i), r, c)){
                                sum += num_combos(i + 1);
                                remove_ship();
                            }
                        }
                        if(c + sizes.at(i) <= n){
                            if(place_horiz(sizes.at(i), r, c)){
                                sum += num_combos(i + 1);
                                remove_ship();
                            }
                        }
                    }
                }
            } 
        }
        return sum;
    }
};


int main(){
    cin >> n >> k;
    
    board bro = board();
    for (long long i = 0; i < k; i++){
        int temp;
        cin >> temp;
        bro.sizes.push_back(temp);
    }
    sort(bro.sizes.begin(), bro.sizes.end(), greater<int>());
    cout << bro.num_combos(0) << endl;
    
    return 0;
}