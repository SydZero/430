#include <bits/stdc++.h>
using namespace std;

int main(){
    long long q, m, s, l;
    cin >> q >> m >> s >> l;

    long long units;

    if(s % q == 0){
        units = s / q;
    } else {
        units = (s / q) + 1;
    }

    units = l + units;

    if(l % m == 0){
        cout << (l / m) * q << endl;
    } else {
        cout << ((l / m) + 1) * q << endl;
    }

    return 0;
}
