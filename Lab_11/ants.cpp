#include <bits/stdc++.h>
using namespace std;


int main(){
 
    int l, n, t;
    cin >> t;

    for(int i = 0; i < t; i++){
        set<int> pos;
        cin >> l >> n;
        

        for(int i = 0; i < n; i++){
            int temp;
            cin >> temp;
            pos.insert(temp);
        }


        int maxl = INT32_MIN;
        int minl = INT32_MIN;

        for(int a : pos){
            minl = max(minl, min(a, l - a));
            maxl = max(maxl, max(a, l - a));
        }

        cout << minl << " " << maxl << endl;
        




    }  
    return 0;
} 