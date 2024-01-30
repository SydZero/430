#include <bits/stdc++.h>
using namespace std;



int main(){
 
    long long t = 0;
    cin >> t;
    long long n;

    for(long long i = 0; i < t; i++){
        cin >> n;
        
        vector<long long> rankings;

        long long num;
        string name;

        for(int j = 0; j < n; j++){
            cin >> name;
            cin >> num;
            rankings.push_back(num);
        }
        sort(rankings.begin(), rankings.end());

        long long  total = 0;
        for(int k = 0; k < rankings.size(); k++){
            //cout << (k+1) << " " << rankings.at(k) << " " << total << endl;


            total += abs(k + 1 - rankings.at(k));
        }

        cout << total << endl;
        
        
    }  
    return 0;
}
