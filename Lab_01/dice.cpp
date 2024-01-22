#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using std::cout, std::cin, std::endl;
using std::string;

int main(){

    int num1, num2;
    cin >> num1 >> num2;

    std::vector<int> probs(num1 + num2 + 1, 0);
    int curr;
    int max = -1;

    for(int i = 1; i <= num1; i++){
        for(int j = 1; j <= num2; j++){
            probs.at(i + j) += 1;
            if(probs.at(i + j) > max){
                max = probs.at(i+j);
            }
        }  
    }

    for(int i = 0; i < probs.size(); i++){
        if (probs.at(i) == max){
            cout << i << endl;
        }
    }
   


    return 0;
}