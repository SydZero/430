#include <iostream>
#include <fstream>
#include <string>

using std::ifstream;
using std::cout, std::cin, std::endl;
using std::string;

int main(){

    int i1;
    cin >> i1;
    int i2;
    cin >> i2;

    cout << i2 << endl;

    string line;
    for(int i = 0; i < i1; i++){
        cin >> line;
    }

    return 0;
}