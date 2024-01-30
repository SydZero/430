#include <bits/stdc++.h>
using namespace std;

int main(){

    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    int n;

    cin >> n;
    vector<string *> strs;
    string temp;
    for(int i = 0; i < n; i++){
        cin >>  temp;
        strs.push_back(new string(temp));
    }

    int a, b;
    int end = 0;
    string * empty = new string ("");
    while(cin >> a >> b){
        a -= 1;
        b -= 1;
        string temp = string(*strs[a] + *strs[b]);
        delete strs[a];
        delete strs[b];
        strs[a] = new string(temp);
        strs[b] = empty;
        end = a;
    }
    cout << *strs[end] << endl;
    
    // for(int i = 0; i < n; i++){
    //     if(*strs[i] != ""){
    //         cout << *strs[i] << endl;
    //         break;
    //     }
    // }

    return 0;
}