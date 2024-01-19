#include <iostream>
#include <string>

using std::cout, std::cin, std::endl;
using std::string;

int main(){

    int num = 0;
    cin >> num;

    int sum = 0;
    int curr = 0;
    for(int i = 0; i < num; i++){
        cin >> curr;
        sum += curr;
    }

    cout << sum << endl;


    return 0;
}