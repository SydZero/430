#include <bits/stdc++.h>
using namespace std;

class board{
public:
    long long rows, cols;
    int** b;
    int** par;

    board(long long rows, long long cols): rows(rows), cols(cols){
        b = new int*[rows];
        par = new int*[rows];
        for (long long r = 0; r < rows; r++){
            b[r] = new int[cols];
            par[r] = new int[cols];
            for (long long c = 0; c < cols; c++){
                cin >> b[r][c];
                par[r][c] = -1;
            }
        }
    }

    long long find_parity(long long r0, long long c0){
        long long parity = -1;
        long long r = r0;
        long long c = c0;

        //ul diagonal
        for (r = r0, c = c0; r >= 0 && c >= 0; r--, c++){
            if(b[r][c] != 0){
                if(parity != -1){
                    if(r % 2 == r0 % 2){
                        if(b[r][c] % 2 != parity){
                            return INT32_MIN;
                        }
                    } else if(b[r][c] % 2 == parity){
                        return INT32_MIN;
                    }
                    
                } else if(parity == -1){
                    if(r % 2 == r0 % 2){
                        parity = b[r][c] % 2;
                    } else {
                        parity = !(bool)(b[r][c] % 2);
                    }
                }
            }
        }

        //ur diagonal
        for (r = r0, c = c0; r >= 0 && c < cols; r--, c++){
            if(b[r][c] != 0){
                if(parity != -1){
                    if(r % 2 == r0 % 2){
                        if(b[r][c] % 2 != parity){
                            return INT32_MIN;
                        }
                    } else if(b[r][c] % 2 == parity){
                        return INT32_MIN;
                    }
                    
                } else if(parity == -1){
                    if(r % 2 == r0 % 2){
                        parity = b[r][c] % 2;
                    } else {
                        parity = !(bool)(b[r][c] % 2);
                    }
                }
            }
        }

        //dl diagonal
        for (r = r0, c = c0; r < rows && c >= 0; r++, c--){
            if(b[r][c] != 0){
                if(parity != -1){
                    if(r % 2 == r0 % 2){
                        if(b[r][c] % 2 != parity){
                            return INT32_MIN;
                        }
                    } else if(b[r][c] % 2 == parity){
                        return INT32_MIN;
                    }
                    
                } else if(parity == -1){
                    if(r % 2 == r0 % 2){
                        parity = b[r][c] % 2;
                    } else {
                        parity = !(bool)(b[r][c] % 2);
                    }
                }
            }
        }

        //dc diagonal
        for (r = r0, c = c0; r < rows && c < cols; r++, c++){
            if(b[r][c] != 0){
                if(parity != -1){
                    if(r % 2 == r0 % 2){
                        if(b[r][c] % 2 != parity){
                            return INT32_MIN;
                        }
                    } else if(b[r][c] % 2 == parity){
                        return INT32_MIN;
                    }
                    
                } else if(parity == -1){
                    if(r % 2 == r0 % 2){
                        parity = b[r][c] % 2;
                    } else {
                        parity = !(bool)(b[r][c] % 2);
                    }
                }
            }  
        }

        //up
        for (long long r = r0; r < rows; r += 2){
            if(b[r][c0] != 0){
                if(parity != -1 && b[r][c0] % 2 != parity){
                    return INT32_MIN;
                } else if(parity == -1){
                    parity = b[r][c0] % 2;
                }
            }
        }

        //down
        for (long long r = r0; r >= 0; r -= 2){
            if(b[r][c0] != 0){
                if(parity != -1 && b[r][c0] % 2 != parity){
                    return INT32_MIN;
                } else if(parity == -1){
                    parity = b[r][c0] % 2;
                }
            }
        }

        //left 
        for (long long c = c0; c >= 0 ; c -= 2){
            if(b[r0][c] != 0){
                if(parity != -1 && b[r0][c] % 2 != parity){
                    return INT32_MIN;
                } else if(parity == -1){
                    parity = b[r0][c] % 2;
                }
            }
        }

        //right
        for (long long c = c0; c < cols; c += 2){
            if(b[r0][c] != 0){
                if(parity != -1 && b[r0][c] % 2 != parity){
                    return INT32_MIN;
                } else if(parity == -1){
                    parity = b[r0][c] % 2;
                }
            }
        }
        return parity;
    }

    long long fill(){
        long long sum = 0;
        bool valid = true;
        long long colmin[cols] = {0};
        for (long long r = 0; valid && r < rows; r++){
            long long rowmin = 0;
            for (long long c = 0; valid && c < cols; c++){
                if(b[r][c] == 0){
                    long long min = 0;
                    min = max(colmin[c], rowmin) + 1;
                    long long parity = find_parity(r, c);
                    if(parity == INT32_MIN){
                        valid = false;
                        break;
                    }
                    if(parity != -1 && min % 2 != parity){
                        min++;
                        parity = min % 2;
                    }
                    
                    b[r][c] = min;
                    
                } else {
                    if(r > 0 && b[r][c] <= b[r-1][c]){
                        valid = false;
                        break;
                    } 
                    if(c > 0 && b[r][c] <= b[r][c-1]){
                        valid = false;
                        break;
                    }
                    if(r > 0 && c > 0 && b[r][c] % 2 == b[r-1][c-1] % 2){
                        valid = false;
                        break;
                    }
                    if(r > 0 && c < cols - 1 && b[r][c] % 2 == b[r-1][c+1] % 2){
                        valid = false;
                        break;
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

    cout << b.fill() << endl;

    b.print();
      
    return 0;
}
