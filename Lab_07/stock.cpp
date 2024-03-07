#include <bits/stdc++.h>
using namespace std;

void print(vector<bool>& v){
    for(long long i = 0; i < v.size(); i++){
        cout << v.at(i) << " ";
    }
    cout << endl;
}


int main(){
    long long num;
    cin >> num;
    
    vector<long long> vals;
    long long currMoney = 100;
    long long numstocks = 0;
    for(long long i = 0; i < num; i++){  
        long long num1;
        cin >> num1;
        vals.push_back(num1);
    }

    for(long long i = 0; i < num - 1; i++){
        if(vals.at(i) > vals.at(i+1)){
            currMoney += numstocks * vals.at(i);
            numstocks = 0;
        } else if(currMoney >= vals.at(i)){
            long long upst = min(currMoney / vals.at(i), 100000 - numstocks);
            numstocks += upst;
            currMoney -= upst * vals.at(i);
        }
    }
    currMoney += numstocks * vals.at(vals.size() - 1);
    cout << currMoney << endl;
      
    return 0;
}
