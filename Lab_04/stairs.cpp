#include <bits/stdc++.h>
using namespace std;


int main(){
    long long n, r, o;
    cin >> n >> r >> o;



    long long maxs = o + abs(r - o);
    
    if(maxs < n){
        maxs += (n - maxs) + ((n - maxs) % 2);
    }

    maxs += r;

    cout << maxs << endl;    

    return 0;
}
