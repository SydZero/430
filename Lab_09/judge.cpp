#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n;

    cin >> n;

    map<string, long long> dom;
    map<string, long long> kattis;

    for (long long i = 0; i < n; i++){
        string temp;
        cin >> temp;
        if(dom.find(temp) != dom.end()){
            dom[temp]++;
        } else {
            dom.insert({temp, 1});
        }
    }

    for (long long i = 0; i < n; i++){
        string temp;
        cin >> temp;
        if(kattis.find(temp) != kattis.end()){
            kattis[temp]++;
        } else {
            kattis.insert({temp, 1});
        }
    }

    long long sum = 0;

    for(pair<string, long long> d : dom){
        auto k = kattis.find(d.first);

        if(k != kattis.end()){
            sum += min(d.second, k->second);
        }
    }
    
    cout << sum;

    return 0;
}
