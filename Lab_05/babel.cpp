#include <bits/stdc++.h>
using namespace std;

int main(){
    string str = "...";
    map<string, string> dict;

    getline(cin, str);
    while(!str.empty()){
        //cout << str << endl;
        stringstream line(str);
        string first;
        string second;

        line >> first >> second;
        dict.insert({second, first});
        getline(cin, str);
    }
        
    while(cin >> str){
        //cout << str << ": ";
        auto found = dict.find(str);
        if(found == dict.end()){
            cout << "eh" << endl;
        } else {
            cout << found->second << endl;
        }
        
    }

    return 0;
}
