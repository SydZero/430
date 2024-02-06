#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n;
    cin >> n;
    long long awkwardness = n;
    map<long long, long long> guests;
    
    for(long long i = 0; i < n; i++){
        long long lang;
        cin >> lang;
        
        if(guests.find(lang) != guests.end()){
            //cout << lang  << " " << i << endl;
            long long curr = guests[lang];
            if(i - curr < awkwardness){
                awkwardness = i - curr;
            }
        }
        guests[lang] = i;
    }
    

    cout << awkwardness << endl;

    return 0;
}
