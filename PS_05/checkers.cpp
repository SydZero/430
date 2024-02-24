#include <bits/stdc++.h>
using namespace std;

int main(){
    int rows, cols;

    cin >> rows >> cols;
    int board[rows][cols];

    for (int r = 0; r < rows; r++){
        for (int c = 0; c < cols; c++){
            cin >> board[r][c];
        }
    }
    long long sum = 0;
    bool valid = true;
    int colmin[cols] = {0};
    
    for (int r = 0; valid && r < rows; r++){
        int rowmin = 0;
        for (int c = 0; valid && c < cols; c++){
            if(board[r][c] == 0){
                int min = 0;
                min = max(colmin[c], rowmin) + 1;
                int parity = -1;
                if(c >= 2){
                    parity = board[r][c-2] % 2;
                }
                if(c + 2 < cols - 1){
                    if(parity == -1){
                        parity = board[r][c-2] % 2;
                    } else if(parity != board[r][c+2] % 2){
                        valid = false;
                        break;
                    }
                }
                if(parity != -1 && min % 2 != parity){
                    min++;
                    parity = min % 2;
                }
                if(r > 0 && c > 0 && board[r-1][c-1] % 2 == min % 2){
                    min++;
                    parity = min % 2; 
                    if(r > 0 && c < cols - 1 && board[r-1][c+1] % 2 == parity){
                        valid = false;
                        break;
                    }
                }
                if(r > 0 && c < cols - 1 && board[r-1][c+1] % 2 == min % 2){
                    min++;
                    parity = min % 2; 
                }
                
                board[r][c] = min;
                
            } else {
                
                if(r > 0 && board[r][c] <= board[r-1][c]){
                    valid = false;
                    break;
                } 
                if(c > 0 && board[r][c] <= board[r][c-1]){
                    valid = false;
                    break;
                }
                if(r > 0 && c > 0 && board[r][c] % 2 == board[r-1][c-1] % 2){
                    valid = false;
                    break;
                }
                if(r > 0 && c < cols - 1 && board[r][c] % 2 == board[r-1][c+1] % 2){
                    valid = false;
                    break;
                }
            }
            rowmin = board[r][c];
            colmin[c] = board[r][c];
            sum += board[r][c];
        }
    }

    if(valid){
        cout << sum << endl;
    } else {
        cout << -1 << endl;
    }

    for (int r = 0; r < rows; r++){
        for (int c = 0; c < cols; c++){
            cout << board[r][c] << " ";
        }
        cout << endl;
    }
      
    return 0;
}
