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

class board{
public:
    char** b;
    vector<pair<int, int>> hits;
    vector<int> sizes;

    board(): hits(0), sizes(0){
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

    bool hits_good(char** check){
        if(check == nullptr){
            return false;
        }
        for(int i = 0; i < hits.size(); i++){
            if(check[hits.at(i).first][hits.at(i).second] != 'O'){
                return false;
            }
        }
        return true;
    }

    char** place_horiz(char** arr, long long s, long long r0, long long c0){
        if(c0 + s > n){
            return nullptr;
        }
        char** arr2 = new char*[n];
        for(int r = 0; r < n; r++){
            arr2[r] = new char[n];
            for(int c = 0; c < n; c++){
                arr2[r][c] = arr[r][c];
            }
        }
        for(int c = c0; c < c0 + s; c++){
            if(arr2[r0][c] == 'O' || arr2[r0][c] == 'X'){
                return nullptr;
            }
            arr2[r0][c] = 'O';
            
        }
        //print_board(arr2);
        return arr2;
    }

    char** place_vert(char** arr, long long s, long long r0, long long c0){
        if(r0 + s > n){
            return nullptr;
        }
        char** arr2 = new char*[n];
        for(int r = 0; r < n; r++){
            arr2[r] = new char[n];
            for(int c = 0; c < n; c++){
                arr2[r][c] = arr[r][c];
            }
        }
        for(int r = r0; r < r0 + s; r++){
            if(arr2[r][c0] == 'O' || arr2[r][c0] == 'X'){
                return nullptr;
            }
            arr2[r][c0] = 'O';
            
        }
        return arr2;
    }

    long long place_final(char** arr, long long s, long long r0, long long c0){
        int sum = 0;
        if(s == 1){
            if(arr[r0][c0] == 'O' || arr[r0][c0] == 'X'){
                return 0;
            }
            arr[r0][c0] = 'O';
            if(hits_good(arr)){
                arr[r0][c0] = '.';
                return 1;
            }
            arr[r0][c0] = '.';
            return 0;
        } else {
            bool found = true;
            if(c0 + s <= n){
                if(hits_good(place_horiz(arr, s, r0, c0))){
                    sum += 1;
                }
            }
            if(r0 + s <= n){
                if(hits_good(place_vert(arr, s, r0, c0))){
                    sum += 1;
                }
            }    
        `   return sum;
        }
    }

    int num_combos(char** arr, long long i){
        int sum = 0;
        if(arr == nullptr){
            return 0;
        }
        for(int r = 0; r < n; r++){
            for(int c = 0; c < n; c++){
                if(arr[r][c] == 'X' || arr[r][c] == 'O'){
                    continue;
                }
                if(i == sizes.size() - 1){
                    sum += place_final(arr, sizes.at(i), r, c);
                } else {
                    if(sizes.at(i) == 1){
                        sum += num_combos(place_vert(arr, sizes.at(i), r, c), i + 1);
                    } else {
                        if(r + sizes.at(i) <= n){
                            sum += num_combos(place_vert(arr, sizes.at(i), r, c), i + 1);
                        }
                        if(c + sizes.at(i) <= n){
                            sum += num_combos(place_horiz(arr, sizes.at(i), r, c), i + 1);
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
    cout << bro.num_combos(bro.b, 0) << endl;
    
    return 0;
}
