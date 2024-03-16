#include <bits/stdc++.h>
using namespace std;

void print(long long* arr, long long n){
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){
    long long n, m;
    cin >> n >> m;
    long long sum_cals[n][n] = {-100};
    long long nice_cals[n][n] = {-100};
    long long cals[n] = {-100};
    long long meals[n] = {-100};
    cals[0] = m;

    cin >> meals[0];
    for(int i = 1; i < n; i++){
        cin >> meals[i];
        cals[i] = cals[i - 1] * (2.0/3.0);
    }

    for(int r = 0; r < n; r++){
        // cout << cals[r] << " ";
        for(int c = n - 1; c >= 0; c--){
            if(r > c){
                sum_cals[r][c] = 0;
                continue;
            }
            if(c < n - 1){
                sum_cals[r][c] = sum_cals[r][c + 1] + min(cals[c - r], meals[c]);
            } else {
                sum_cals[r][c] = min(cals[c - r], meals[c]);
            }
            nice_cals[r][c] = min(cals[c - r], meals[c]);
        }
    }
    // cout << endl;

    // for(int r = 0; r < n; r++){
    //     print(sum_cals[r], n);
    // }
    // cout << "_________" << endl;
    // for(int r = 0; r < n; r++){
    //     print(nice_cals[r], n);
    // }
    
    long long sum = sum_cals[0][0];

    int r = 0;

    for(int c = 0; c < n - 1; c++){
        if(sum_cals[r][c] <= sum_cals[r + 1][c + 1]){
            sum += sum_cals[r + 1][c + 1] - sum_cals[r][c];
            r++;
        }
    }

    cout << sum << endl;
    
    
      
    return 0;
}
