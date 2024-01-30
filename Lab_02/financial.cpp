#include <bits/stdc++.h>
using namespace std;

//determine how many days to make money
// (c/p) + 1 - (int division)
// 1: add first profitable dayamount for each investment from that day
//  how many more days to meet M


int main(){
    long long n, M, p, c;
    cin >> n >> M;
    unordered_map<int, pair<long long, long long>> nums;
    

    for(long long i = 0; i < n; i++){
        cin >> p >> c;
        nums.emplace(make_pair(p, c));
        
    }

    long long days = ceil(((c + M) * 1.0) / p);
    c = 0;
    p = 0;
    long long min = LONG_MAX;
    long long overallmin = LONG_MAX;
    
    for(long long j = 0; j < n; j++){
        if(min < overallmin){
            overallmin = min;
        }
        c = 0;
        p = 0;
        for(long long i = j; i < n; i++){
            long long newdays = ceil(((c + M + nums.at(i).second) * 1.0) / (p + nums.at(i).first));
            if(newdays < min){
                min = newdays;
                c += nums.at(i).second;
                p += nums.at(i).first;
            }
        }
    }
    cout << min << endl;

    return 0;
}
