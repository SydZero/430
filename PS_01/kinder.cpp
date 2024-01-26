#include <bits/stdc++.h>
using namespace std;

int main(){

    vector<int> nums;
    
    string word;
    cin >> word;

    long long swaps = 0;

    long long zeros = 0;
    long long ones = 0;
    long long twos = 0;

    for(int i = 0; i < word.length(); i++){
        nums.push_back(word[i] - '0');
        if(nums[i] == 0){
            zeros++;
        }
        if(nums[i] == 1){
            ones++;
        }
        if(nums[i] == 2){
            twos++;
        }
    }
    
    for(int i = 0; i < nums.size(); i++){
        if(nums[i] == 0){
            zeros--;
        }
        if(nums[i] == 1){
            ones--;
            swaps += zeros;
        }
        if(nums[i] == 2){
            twos--;
            swaps += zeros + ones;
        }
        
    }

    cout << swaps << endl;

    return 0;
}