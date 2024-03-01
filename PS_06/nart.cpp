#include <bits/stdc++.h>
using namespace std;


typedef vector<vector<int>> Gallery;
typedef vector<vector<vector<int>>> DPMat;

int find_path(int k, int r, int c, Gallery& gallery, DPMat& dpmat){
    cout << "  find path: " << k << " " << r << " " << c << endl;
    if(c == INT32_MIN){
        return min(find_path(k, r, 0, gallery, dpmat), find_path(k, r, 1, gallery, dpmat));
    }
    if(r >= 0 && k > 0){
        if(dpmat[k][r][c] == 0){
            int val1 = find_path(k - 1, r - 1, c, gallery, dpmat) + gallery[r][c];
            int val2 = find_path(k, r - 1, INT32_MIN, gallery, dpmat);
            dpmat[k][r][c] = min(val1, val2);
        }
        return dpmat[k][r][c];
    } else if(k == 0){
        return 0;
    }
    return INT32_MAX;
}

int main(){
    long long n, k;
    while(cin >> n >> k){
        if(n == 0 && k == 0){
            break;
        }
        Gallery gallery(n, vector<int>(2));
        DPMat dpmat(k + 1, Gallery(n, vector<int>(2)));
        for(int i = 0; i < n; i++){
            cin >> gallery[i][0] >> gallery[i][1];
        }
        int sum = 0;
        for(int i = 0; i < n; i++){
            sum += gallery[i][0] + gallery[i][1];
        }

        for(int j = 0; j < n; j++){
            cout << gallery[j][0] << " " << gallery[j][1] << endl;
        }
        cout << sum - find_path(k, n-1, INT32_MIN, gallery, dpmat) << endl;
        for(int i = 0; i < k + 1; i++){
            for(int j = 0; j < n; j++){
                cout << dpmat[i][j][0] << " " << dpmat[i][j][1] << endl;
            }
            cout << endl;
        }
    }
      
    return 0;
}
