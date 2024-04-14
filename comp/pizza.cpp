#include <bits/stdc++.h>
using namespace std;

long time(long x1, long y1, long x2, long y2){
    long diffx = abs(x2 - x1);
    long diffy = abs(y2 - y1);
    
    return max(diffx, diffy);
}


int main(){
    long n, k;
    long x, y;

    cin >> n >> k;

    vector<pair<long, long>> buildings;
    vector<long> times;

    for(int i = 0; i < n; i++){
        cin >> x >> y;

        for(pair<long, long> p : buildings){
            times.push_back(time(x, y, p.first, p.second));
        }
        buildings.push_back(make_pair(x, y));
    }

    sort(times.begin(), times.end(), less<long>());


    if(k-1 >= times.size()){
        cout << INT32_MAX << endl;
        return 0;
    }
    
    cout << times.at(k - 1) << endl;
    
    return 0;
}
