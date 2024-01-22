#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using std::cout, std::cin, std::endl;
using std::string;

struct hotel {
    int cost;
    std::vector<int> beds;
};

int main(){

    int N, B, H, W;
    cin >> N >> B >> H >> W;
    std::vector<hotel> hotels;

    for(int i = 0; i < H; i++){
        hotel temp;
        cin >> temp.cost;
        for(int j = 0; j < W; j++){
            int beds;
            cin >> beds;
            temp.beds.push_back(beds);
        }
        hotels.push_back(temp);
        
    }
    int min = 5000000;
    for(int i = 0; i < hotels.size(); i++){
        for(int j = 0; j < hotels.at(i).beds.size(); j++){
            if(hotels.at(i).cost * N > B){
                continue;
            }
            if(hotels.at(i).beds.at(j) > N && hotels.at(i).cost * N < min){
                min = hotels.at(i).cost * N;
            }
        }
            
    }
    if(min == 5000000){
        cout << "stay home";
    } else {
        cout << min;
    }

   
   


    return 0;
}