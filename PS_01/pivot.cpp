#include <bits/stdc++.h>
using namespace std;

int main(){

    int num = 0;
    cin >> num;
    int nums[num];
    int curr;
    int max = INT32_MIN;
    set<int> numset;
    
    for(int i = 0; i < num; i++){
        cin >> curr;
        nums[i] = curr;
        if(curr > max){
            max = curr;
            numset.emplace(curr);
        }
        
    }

    int min = INT32_MAX;
    for(int j = num - 1; j >= 0; j--){
        if(nums[j] < min){
            min = nums[j];
        } else {
            numset.erase(nums[j]);
        }
    }
    
    cout << numset.size() << endl;

    return 0;
}