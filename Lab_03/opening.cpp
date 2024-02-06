#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n;
    long long h = 0;
    long long v = 0;
    long long total = 0;

    cin >> n;

    map<long long, long long, greater<long long>> nums;
    
    for(long long i = 0; i < n; i++){
        long long lang;
        cin >> lang;
        if(nums[lang]){
            nums[lang] += 1;
        } else {
            nums[lang] = 1;
        }
    }    
    long long minl = LONG_LONG_MAX;
    for(auto i = nums.begin(); i != nums.end(); i++){
        //cout << i->first << " " << i->second << endl;
        minl = min((i->first) + total, minl);
        total += i->second;
    }

    cout << min(minl, n) << endl;

    return 0;
}
