#include <bits/stdc++.h>
using namespace std;

int main(){

    vector<int> nums;
    string word;
    cin >> word;

    int swaps = 0;

    for(int i = 0; i < word.length(); i++){
        nums.push_back(word[i] - '0');
        if(i > 0 && nums[i] < nums[i-1]){
            swap(nums[i], nums[i-1]);
            swaps++;
        }
    }

    bool finished = false;
    while(!finished){
        finished = true;
        for(int i = 1; i < nums.size(); i++){
            int j = i;
            if(j > 0 && nums[j] < nums[j-1]){
                swap(nums[j], nums[j-1]);
                swaps++;
                finished = false;
            }
        }
    }
    
    // for(int i = 1; i < nums.size(); i++){
    //     int j = i;
    //     int curr = nums[j];
    //     while(j > 0 && curr < nums[j-1]){
    //         nums[j] = nums[j-1];
    //         swaps++;
    //         j--;
    //     }
    //     nums[j] = curr;
    // }

    cout << swaps << endl;

    return 0;
}