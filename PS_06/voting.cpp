#include <bits/stdc++.h>
using namespace std;

int n, m;

int recurse(int** DP, int** prefs){
    int i = m;
    for(int j = 0; j < 8; j++){
        int a = j ^ 0b1;
        int b = j ^ 0b10;
        int c = j ^ 0b100;
        for(int k = 0; k < 8; k++){
            if(prefs[i][k] == a){
                DP[i][j] = a;
                break;   
            }
            if(prefs[i][k] == b){
                DP[i][j] = b;
                break;   
            }
            if(prefs[i][k] == c){
                DP[i][j] = c;
                break;   
            }
        }
    }
    for(i = m - 1; i > 0; i--){
        for(int j = 7; j >= 0; j--){
            int a = j ^ 0b1;
            int b = j ^ 0b10;
            int c = j ^ 0b100;
            for(int k = 0; k < 8; k++){
                if(DP[i + 1][a] == prefs[i][k]){
                    DP[i][j] = a;
                    break;   
                }
                if(DP[i + 1][b] == prefs[i][k]){
                    DP[i][j] = b;
                    break;   
                }
                if(DP[i + 1][c] == prefs[i][k]){
                    DP[i][j] = c;
                    break;   
                }
            }
        }
    }
    for(i = 1; i <= m; i++){
        for(int j = 0; j < 8; j++){
            cout << DP[i][j];
        }
        cout << endl;
    }
    return DP[1][0];
}

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for(int k = 0; k < n; k++){
        cin >> m;
        int** prefs = new int*[m + 1];
        int** dp = new int*[m + 1];
        for(int l = 1; l <= m; l++){
            prefs[l] = new int[8];
            dp[l] = new int[8];
            for(int i = 0; i < 8; i++){
                int pref;
                cin >> pref;
                prefs[l][pref - 1] = i;
                
            }
        }
        

        int result = recurse(dp, prefs);
        if(result & 0b100){
            cout << 'Y';
        } else {
            cout << 'N';
        }
        if(result & 0b10){
            cout << 'Y';
        } else {
            cout << 'N';
        }
        if(result & 0b1){
            cout << 'Y';
        } else {
            cout << 'N';
        }
        cout << endl;
    }
      
    return 0;
}