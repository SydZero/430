#include <bits/stdc++.h>
using namespace std;

int main(){

    int num = 0;
    cin >> num;
    int nums[num];
    int curr;
    int max = INT32_MIN;
    
    for(int i = 0; i < num; i++){
        cin >> curr;
        nums[i] = curr;
    }

    int pivots = num;
    for(int i = 0; i < num; i++){
        curr = nums[i];
        if(curr > max){
            max = curr;
            for(int j = i + 1; j < num; j++){
                if(nums[j] < nums[i]){
                    pivots--;
                    break;
                }
            }
        } else {
            pivots--;
        }
        
    }
    
    cout << pivots << endl;

    return 0;
}