#include <bits/stdc++.h>
using namespace std;


void print_set(set<string> strs){
    for(auto j = strs.begin(); j != strs.end(); j++){
        cout << *j << " ";
    }
    cout << endl;
}

int main(){
    int t, n;
    cin >> t;

    map<string, pair<string, set<string>>> ingredse;
    map<string, pair<string, set<string>>> ingredsf;



    for(int j = 0; j < t; j++){
        cin >> n;
        map<string, set<string>> english;
        map<string, set<string>> foreign;

        for(int i = 0; i < n; i++){
            string name, ingredient;
            int num;
            cin >> name;
            cin >> num;


            for (int k = 0; k < num; k++) {
                cin >> ingredient;
                foreign[ingredient].insert({name});
            }

            cin >> num;
            for (int k = 0; k < num; k++) {
                cin >> ingredient;
                english[ingredient].insert({name});
            }
        } 

        for(auto i = foreign.begin(); i != foreign.end(); i++){
            for(auto j = english.begin(); j != english.end(); j++){
                if(i == j || i->second.size() != j->second.size()){
                    continue;
                }
                if(i->second == j->second){
                    cout << "(" << i->first << ", " << j->first << ")" << endl;
                }
            }
        }
        cout << endl;
    }

    return 0;
}
