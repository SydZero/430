#include <bits/stdc++.h>
using namespace std;

void print(vector<bool>& v){
    for(int i = 0; i < v.size(); i++){
        cout << v.at(i) << " ";
    }
    cout << endl;
}


int main(){
    long long stones, nums;
    while(cin >> stones >> nums){
        vector<int> vals;
        vector<bool> whowins(stones + 1, false);
        for(int i = 0; i < nums; i++){
            int num;
            cin >> num;
            vals.push_back(num);
        }
        for(int j = 0; j <= stones; j++){
            for(int i = 0; i < nums; i++){
                if(j >= vals.at(i) && !whowins[j - vals.at(i)]){
                    whowins[j] = true;
                    break;
                }
            }
        }
        if(whowins[stones] == false){
            cout << "Ollie wins" << endl;
        } else {
            cout << "Stan wins" << endl;
        }
    }
      
    return 0;
}
