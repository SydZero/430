#include <bits/stdc++.h>
using namespace std;

int main(){

    vector<int> nums;
    string word;
    cin >> word;

    int swaps = 0;

    int zeros = 0;
    int ones = 0;
    int twos = 0;

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
    
    // bool finished = false;
    // for(int i = nums.size() - 1; i > 0; i--){
    //     int j = 0;
    //     while(j < i){
    //         if(nums[j] > nums[j + 1]){
    //             swap(nums[j], nums[j + 1]);
    //             swaps++;
    //         }
    //         j++;
    //     }
        
    // }
    int jtot = 0;
    //tree loops to put 0, 1, 2 in place in order
    for(int k = 0; k < 3; k++){
        int j = 0;
        for(int i = nums.size() - 1; i - j > 0; i--){
            if(nums[i - j] == k){
                j++;
            }
            if(j > 0 && i - j >= 0){
                nums[i] = nums[i - j];
                swaps++;
            }
        }
        jtot += j;
}
    


    cout << swaps << endl;

    return 0;
}