#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using std::cout, std::cin, std::endl;
using std::string;

int main(){

    int n, k;
    cin >> n >> k;

    int curr;
    double avg;

    for(int i = 0; i < k; i++){
        cin >> curr;
        avg += curr;
    }

    int remaining = n - k;

    //min poss
    double minavg = 1000000;

    //max poss
    double maxavg = -1000000;

    for(int i = -3; i <= 3; i++){
        double curravg = (avg + (remaining * i)) / n;
        if(curravg > maxavg){
            maxavg = curravg;
        }
        if(curravg < minavg){
            minavg = curravg;
        }
    }
    
    cout << minavg << " " << maxavg;

    return 0;
}