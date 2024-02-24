#include <bits/stdc++.h>
using namespace std;
int main(){
    string t;
    set<string> ogwords;
    set<string> newwords;
    while(cin >> t){
        ogwords.emplace(t);
      
    }

    for(auto i = ogwords.begin(); i != ogwords.end(); i++){
        for(auto j = ogwords.begin(); j != ogwords.end(); j++){
            if(i != j){
                newwords.emplace((*i)+ (*j));
            }
        }
    }

    for(auto i = newwords.begin(); i != newwords.end(); i++){
        cout << *i << endl;
    }

      
    return 0;
}
