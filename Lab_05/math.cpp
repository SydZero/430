#include <bits/stdc++.h>
using namespace std;

string to_binary(string n){
    string bin = "";
    for(int i = 0; i < n.size(); i++){
        switch(n.at(i)){
            case '0':
                bin += "000";
                break;
            case '1':
                bin += "001";
                break;
            case '2' :
                bin += "010";
                break;
            case '3':
                bin += "011";
                break;
            case '4':
                bin += "100";
                break;
            case '5' :
                bin += "101";
                break;
            case '6':
                bin += "110";
                break;
            case '7':
                bin += "111";
                break;
       }
    }

    //cout << bin << endl;
    return bin;
}

string to_hex(string binary){
    string hex = "";
    bool done = false;
    for(int i = binary.size() - 4; i >= -3; i -= 4){
        if(i == 0){
            done = true;
        }
        string curr = "";
        for(int j = 0; j < 4; j++){
            if(i + j < 0){
                curr += '0';
            } else {
                curr += binary.at(i + j);
            }
            //cout << curr << endl;
        }
        if(curr == "0000"){
            hex = "0" + hex;
        }
        if(curr == "0001"){
            hex = "1" + hex;
        }
        if(curr == "0010"){
            hex = "2" + hex;
        }
        if(curr == "0011"){
            hex = "3" + hex;
        }
        if(curr == "0100"){
            hex = "4" + hex;
        }
        if(curr == "0101"){
            hex = "5" + hex;
        }
        if(curr == "0110"){
            hex = "6" + hex;
        }
        if(curr == "0111"){
            hex = "7" + hex;
        }
        if(curr == "1000"){
            hex = "8" + hex;
        }
        if(curr == "1001"){
            hex = "9" + hex;
        }
        if(curr == "1010"){
            hex = "A" + hex;
        }
        if(curr == "1011"){
            hex = "B" + hex;
        }
        if(curr == "1100"){
            hex = "C" + hex;
        }
        if(curr == "1101"){
            hex = "D" + hex;
        }
        if(curr == "1110"){
            hex = "E" + hex;
        }
        if(curr == "1111"){
            hex = "F" + hex;
        }

    }
    return hex;
}


int main(){
    string n;
    
    cin >> n;
    string str = to_hex(to_binary(n));

    while(str.size() >= 2 && str.at(0) == '0'){
        str = str.substr(1, str.size());
    }

    cout << str << endl;
      
    return 0;
}
