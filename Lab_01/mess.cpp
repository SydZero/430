#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>


using std::cout, std::cin, std::endl;
using std::string;

int main(){

    int num = 0;
    cin >> num;
    std::vector<string> messages;
    string mess;
    for(int i = 0; i < num; i++){
        cin >> mess;
        messages.push_back(mess);
    }

    for(int i = 0; i < messages.size(); i++){
        int L = messages.at(i).length();
        int K = ceil(sqrt(L));
        int M = K * K;
        messages.at(i).append((M-L), '*');
        std::vector<std::vector<char>> array(K);
        int curr = 0;
        for(int c = K - 1; c >= 0; c--){
            for(int r = 0; r < K; r++){
                array.at(c).push_back(messages.at(i).at(curr));
                curr++;
            }
        }

        for(int r = 0; r < K; r++){
            for(int c = 0; c < K; c++){
                if(array.at(c).at(r) != '*'){
                    cout << array.at(c).at(r);
                }
            }   
        }
        cout << endl;
    }




    


   


    return 0;
}