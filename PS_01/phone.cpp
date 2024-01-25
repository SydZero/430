#include <bits/stdc++.h>
using namespace std;



int main(){
    // std::ios::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);
    
    int t = 0;
    cin >> t;
    int n;

    for(int i = 0; i < t; i++){
        cin >> n;
        vector<string> strs(n);
        bool valid = true;
        
        for(int j = 0; j < n; j++){
            cin >> strs[j];
            if(!valid){
                continue;
            }
            for(int k = j - 1; k >= 0; k--){
                if(j == k){
                    continue;
                }
                string numk = strs[k];
                string numj = strs[j];
                //cout << numk << " " << numj << "?" << endl;
                if(numj.length() < numk.length() && numk.find(numj) != string::npos){
                    valid = false;
                    //cout << "FLAG 1" << endl;
                    break;
                } else if(numj.length() > numk.length() && numj.find(numk) != string::npos){
                    valid = false;
                    //cout << "FLAG 2:" << numj << " " << numk << endl;
                    break;
                } else if(numj == numk){
                    valid = false;
                    //cout << "FLAG 3" << endl;
                    break;
                }
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
