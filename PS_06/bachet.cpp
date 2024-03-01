#include <bits/stdc++.h>
using namespace std;

void print(vector<bool>& v){
    for(int i = 0; i < v.size(); i++){
        cout << v.at(i) << " ";
    }
    cout << endl;
}


int main(){
    long long stones;
    while(cin >> stones){
        long long nums;
        cin >> nums;
        vector<bool> whowins(stones + 1, false);
        for(int i = 0; i < nums; i++){
            int num;
            cin >> num;
            for(int j = 0; j < nums; j++){
                if(j == 0){
                    break;
                }
                if(j % num == 0){
                    whowins[j] = whowins[j] || !whowins[j - 1];
                }
            }
            if(whowins.size() < 40){
                print(whowins);
            }
        }
        cout << whowins[stones] << endl;
    }
      
    return 0;
}
