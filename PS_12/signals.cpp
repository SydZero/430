#include <bits/stdc++.h>
using namespace std;

int binsearch(vector<int>& dp, int num){ 
    int l = 0;
    int r = dp.size() - 1;
    while(l <= r){
        int m = (r + l) / 2;
        if(dp.at(m) < num){
            l = m + 1;
        } else {
            r = m - 1;
        }
    }
    // cout << num << ": " << l << endl;
    return l;
}

int longest(vector<int>& nums){
    vector<int> dp;
    dp.push_back(INT32_MIN);
    dp.push_back(nums.at(0));
    
    for(int i = 1; i < nums.size(); i++){
        int index = binsearch(dp, nums.at(i));
        if(index == dp.size()){
            dp.push_back(nums.at(i));
        } else if(index == -1){
            dp.at(0) = nums.at(i);
        } else {
            dp.at(index) = nums.at(i);
        }
        // for(int j:dp){
        //     cout << j << " ";
        // }
        // cout << endl;
    }  
    return dp.size() - 1;
}


int main(){
    int p;
    cin >> p;
    vector<int> nums;

    for(int i = 0; i < p; i++){
        int temp;
        cin >> temp;
        nums.push_back(temp);
    }  

    cout << longest(nums) << endl;

    return 0;
} 