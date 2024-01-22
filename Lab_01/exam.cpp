#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


using std::cout, std::cin, std::endl;
using std::string;

int main(){

    int num = 0;
    cin >> num;
    std::vector<char> answers;
    char curr;
    for(int i = 0; i < num; i++){
        cin >> curr;
        answers.push_back(curr);
    }

    int count = 0;
    for(int i = 0; i < answers.size()-1; i++){
        if(answers.at(i) == answers.at(i+1)){
            count++;
        }
    }
    cout << count;
    
   


    return 0;
}