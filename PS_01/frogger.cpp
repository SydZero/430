#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


using std::cout, std::cin, std::endl;
using std::string;

int main(){

    int n, s, m;
    cin >> n >> s >> m;
    std::vector<std::pair<int, bool>> nums;
    int curr;

    for(int i = 0; i < n; i++){
        cin >> curr;
        nums.push_back(std::make_pair(curr, false));
    }


    int index = s - 1;
    int instruction = nums.at(index).first;
    nums.at(index).second = true;
    int hops = 0;
    while(hops <= n){
        if(instruction == m){
            cout << "magic" << endl;
            break;
        } else {
            index += instruction;
            if(index < 0){
                cout << "left" << endl;
                hops++;
                break;
            } else if(index >= nums.size()){
                cout << "right" << endl;
                hops++;
                break;
            }
            if(nums.at(index).second == true){
                cout << "cycle" << endl; 
                hops++;
                break;
            }
            hops++;
            nums.at(index).second = true;

        }
        
        instruction = nums.at(index).first;
    }
    cout << hops << endl;
    return 0;
}