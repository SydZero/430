#include <bits/stdc++.h>
using namespace std;

int main(){
    long long t;
    cin >> t;

    vector<long long> citations;
    for(long long i = 0; i < t; i++){
        long long temp;
        cin >> temp;
        citations.push_back(temp);
      
    }

    sort(citations.begin(), citations.end(), less<long long>());

    long long maxm = 0;
    long long numgreater = 0;
    bool found = false;
    for(long long i = 1; i <= citations.size(); i++){
        if(citations.at(citations.size() - i) >= i){
            maxm = max(maxm, i);
        }
        if(citations.at(citations.size() - i) <= i){
            maxm = max(maxm, citations.at(citations.size() - i));
        }
    }
    cout << maxm << endl;
      
    return 0;
}
