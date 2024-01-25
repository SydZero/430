#include <bits/stdc++.h>
using namespace std;

int main(){

    vector<int> nums;
    string word;
    cin >> word;

    int swaps = 0;

    for(int i = 0; i < word.length(); i++){
        nums.push_back(word[i] - '0');
    }
    
    bool finished = false;
    for(int i = nums.size() - 1; i > 0; i--){
        int j = 0;
        while(j < i){
            if(nums[j] > nums[j + 1]){
                swap(nums[j], nums[j + 1]);
                swaps++;
            }
        }
        
    }
        // finished = true;
        // for(int i = 1; i < nums.size(); i++){
        //     int j = i;
        //     if(j > 0 && nums[j] < nums[j-1]){
        //         swap(nums[j], nums[j-1]);
        //         swaps++;
        //         finished = false;
        //     }
        // }
    

    cout << swaps << endl;

    return 0;
}