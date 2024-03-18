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
   
    for(int c = n - 1; c >= 0; c--){
        for(int r = 0; r < n; r++){     
            nice_cals[r][c] = min(cals[c - r], meals[c]);   
            // cout << "filling " << r << " " << c << endl;
            if(r > c){
                sum_cals[r][c] = sum_cals[c][c];
                nice_cals[r][c] = 0;
                continue;
            }
            nice_cals[r][c] = min(cals[c - r], meals[c]);
            long long eat = 0;
            long long skip1 = 0;
            long long skip2 = 0;
            if(c + 1 < n){
                eat = nice_cals[r][c] + sum_cals[r][c + 1];
                // cout << "   eat: " << eat << endl;
                if(r + 2 < n){
                    skip1 = sum_cals[r + 2][c + 1];
                    // cout << "   skip1: " << skip1 << endl;
                }
                if(c + 2 < n){
                    skip2 = sum_cals[c + 2][c + 2];
                    // cout << "   skip2: " << skip2 << endl;
                }
                sum_cals[r][c] = max(eat, max(skip1, skip2));
            } else {
                sum_cals[r][c] = nice_cals[r][c];
            }
            // cout << "filled with: " << sum_cals[r][c] << endl;
            
        }
    }

    // for(int r = 0; r < n; r++){
    //     print(nice_cals[r], n);
    // }
    // cout << "_________" << endl;
    // for(int r = 0; r < n; r++){
    //     print(sum_cals[r], n);
    // }
    
    cout << sum_cals[0][0] << endl;
    
    return 0;
}