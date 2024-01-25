#include <bits/stdc++.h>
using namespace std;



int main(){
 
    int t = 0;
    cin >> t;
    int n;

    for(int i = 0; i < t; i++){
        cin >> n;
        vector<string> strs(n);
        
        for(int j = 0; j < n; j++){
            cin >> strs[j];
        }
        
        //sorting strings does it ALPHABETICALLY, not by size lol
        sort(strs.begin(), strs.end());

        bool valid = true;
        for(int j = 0; j < n - 1; j++){
            if(strs[j + 1].length() > strs[j].length() && strs[j + 1].find(strs[j]) == 0){
                valid = false;
                break;
            }
        }
        if(valid){
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }  
    return 0;
}
