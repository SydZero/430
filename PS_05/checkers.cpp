#include <bits/stdc++.h>
using namespace std;

class board{
public:
    long long rows, cols;
    int** b;
    int** par;
    vector<pair<int, int>> prefilled;
    bool valid;

    board(long long rows, long long cols): rows(rows), cols(cols), prefilled(0), valid(true){
        b = new int*[rows];
        par = new int*[rows];
        for (long long r = 0; r < rows; r++){
            b[r] = new int[cols];
            par[r] = new int[cols];
            for (long long c = 0; c < cols; c++){
                cin >> b[r][c];
                if(b[r][c] != 0){
                    par[r][c] = b[r][c] % 2;
                    prefilled.push_back({r, c});
                } else {
                    par[r][c] = -1;
                }
            }
        }
        for(pair<int, int> coord : prefilled){
            valid = find_parity(coord.first, coord.second) && valid;
        }
    }

    void flip(){
        int** b2;
        int** par2;
        b2 = new int*[cols];
        par2 = new int*[cols];
        for (long long r = 0; r < cols; r++){
            b2[r] = new int[rows];
            par2[r] = new int[rows];
            for (long long c = 0; c < rows; c++){

                b2[r][c] = b[c][r];
                par[r][c] = par[c][r];
            }
        }
        b = b2;
        swap(rows, cols);
    }

    bool find_parity(long long r0, long long c0){
        long long parity = b[r0][c0] % 2;
        long long opp_parity = (b[r0][c0] + 1) % 2;

        for(long long r = 0; r < rows; r++){
            for(long long c = 0; c < cols; c++){
                if(r % 2 == r0 % 2 && c % 2 == c0 % 2){
                    if(par[r][c] != -1 && par[r][c] != parity){
                        par[r][c] = INT32_MIN;
                        return false;
                    } else {
                        par[r][c] = parity;
                    }
                } else if (r % 2 != r0 % 2 && c % 2 != c0 % 2){
                    if(par[r][c] != -1 && par[r][c] == parity){
                        par[r][c] = INT32_MIN;
                        return false;
                    } else {
                        par[r][c] = opp_parity;
                    }
                }
            }
        }        
        return true;
    }

    void print_board(){
    cout << "___________________" << endl;
    for(long long r = 0; r < rows; r++){
        for(long long c = 0; c < cols; c++){
            cout << b[r][c] << " ";
        }
        cout << endl;
    }
    cout << "   ------------    " << endl;
    for(long long r = 0; r < rows; r++){
        for(long long c = 0; c < cols; c++){
            cout << par[r][c] << " ";
        }
        cout << endl;
    }
    cout << "___________________" << endl;
}

    long long fill(){
        
        long long sum = 0;
        long long colmin[cols] = {0};
        for (long long r = 0; valid && r < rows; r++){
            long long rowmin = 0;
            for (long long c = 0; valid && c < cols; c++){
                if(!valid){
                    return -1;
                }
                if(b[r][c] == 0){
                    long long min = 0;
                    min = max(colmin[c], rowmin) + 1;
                    
                    if(par[r][c] != -1 && par[r][c] != min % 2){
                        min++;
                    } 
                    
                    b[r][c] = min;

                    if(par[r][c] == -1){
                        par[r][c] = min % 2;
                        if(!find_parity(r, c)){
                            valid = false;
                            return -1;
                        }
                    } 
                    
                    
                } else {
                    if(r > 0 && b[r][c] <= b[r-1][c]){
                        valid = false;
                        return -1;
                    } 
                    if(c > 0 && b[r][c] <= b[r][c-1]){
                        valid = false;
                        return -1;
                    }
                }
                rowmin = b[r][c];
                colmin[c] = b[r][c];
                sum += b[r][c];
            }
        }
        if(valid){
            return sum;
        }
        return -1;
    }

    

    void print(){
        for (long long r = 0; r < rows; r++){
            for (long long c = 0; c < cols; c++){
                cout << b[r][c] << " ";
            }
            cout << endl;
        }
    }

};

int main(){
    long long r, c;
    cin >> r >> c;
    
    board b = board(r, c);
    
    if(r > c){
        b.flip();
    }
    
    cout << b.fill() << endl;

    //b.print();
      
    return 0;
}
