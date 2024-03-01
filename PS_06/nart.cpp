#include <bits/stdc++.h>
using namespace std;

typedef vector<vector<int>> Gallery;
typedef vector<vector<vector<int>>> DPMat;

//helloooo
//I have been working for so longggg
//heellllpppp

//DP recursion
int find_path(int k, int r, int c, Gallery& gallery, DPMat& dpmat){
    //if prev row had no room closed
    if(c == INT32_MIN){
        int ret = min(find_path(k, r, 0, gallery, dpmat), find_path(k, r, 1, gallery, dpmat));
        return ret;
    }
    //removing nothing
    if(k == 0){
        return 0;
    }

    //if not valid row in array
    //return val which will not be kept by min fxns
    if(r < 0){
        return 1000000;
    }
    
    //if not already calculated
    if(dpmat[k][r][c] != 0){
        return dpmat[k][r][c];
    }
    //find min path if thisone is closed
    int val1 = find_path(k - 1, r - 1, c, gallery, dpmat) + gallery[r][c];
    //find min path if this is open
    int val2 = min(find_path(k, r - 1, 0, gallery, dpmat), find_path(k, r - 1, 1, gallery, dpmat));

    //min value of the options
    dpmat[k][r][c] = min(val1, val2);
    
    //return partial sum  
    return dpmat[k][r][c];
}


int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);

    long long n, k;
    cin >> n >> k;
    // if(n == 0 && k == 0){
    //     break;
    // }


    Gallery gallery(n, vector<int>(2));
    DPMat dpmat(k + 1, Gallery(n, vector<int>(2)));
    int sum = 0;
    for(int i = 0; i < n; i++){
        cin >> gallery[i][0] >> gallery[i][1];
        sum += gallery[i][0] + gallery[i][1];
    }
    cout << sum - find_path(k, n-1, INT32_MIN, gallery, dpmat) << endl;
    long long temp;
    cin >> temp >> temp;
    return 0;
}