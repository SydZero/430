#include <bits/stdc++.h>
using namespace std;

int main(){
    long long q, m, s, l;
    cin >> q >> m >> s >> l;

    long long ones;
    long long qs;

    if(l % m == 0){
        qs = (l / m);
    } else {
        qs = ((l / m) + 1);
    }

    if(s % m == 0){
        ones = s / m;
    } else {
        ones = (s / m) + 1;
    }

    

    

    return 0;
}
