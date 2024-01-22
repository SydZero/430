#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


using std::cout, std::cin, std::endl;
using std::string;

int main(){

    int num = 0;
    cin >> num;
    std::vector<int> nums;
    int curr;
    for(int i = 0; i < num; i++){
        cin >> curr;
        nums.push_back(curr);
    }

    std::sort(nums.begin(), nums.end());

    for(int i = 0; i < nums.size(); i++){
        cout << nums.at(i);
        if(i + 2 < nums.size() && nums.at(i) + 2 == nums.at(i+2)){
            cout << "-";
            while(i < nums.size() - 1 && nums.at(i + 1) == nums.at(i) + 1){
                i++;
            }
            if(i == nums.size()){
                cout << nums.at(i - 1);
            } else {
                cout << nums.at(i);
            }
        
        }        
        cout << " ";
    }
   


    return 0;
}