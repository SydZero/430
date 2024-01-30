#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


using std::cout, std::cin, std::endl;
using std::string;

int main(){

    string input;
    cin >> input;
    
    int whitespace = 0;
    int lower = 0;
    int upper = 0;
    int symbols = 0;
    
    for(int i = 0; i < input.length(); i++){
        char curr = input.at(i);
        if((curr >= 33 && curr <= 64) || (curr >= 91 && curr <= 96) || (curr >= 123 && curr <= 126)){
            if(curr == 95){
                whitespace++;
            } else {
                symbols++;
            }
        } else if(curr>= 65 && curr <= 90){
            upper++;
        } else if(curr >= 97 && curr <= 122){
            lower++;
        }
        
    }
    double r1, r2, r3, r4;
    r1 = (whitespace);
    r2 = (lower);
    r3 = (upper);
    r4 = (symbols);
    cout << r1/input.length()<< endl;
    cout << r2/input.length() << endl;
    cout << r3/input.length() << endl;
    cout << r4/input.length() << endl;

    return 0;
}