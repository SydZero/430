#include <bits/stdc++.h>
using namespace std;

int main(){
    long long q, m, s, l;
    cin >> q >> m >> s >> l;

    long long ones = 0;
    long long qs = 0;

    qs = (l / m);
    
    if((l % m) != 0){
        qs++;
    }

    long long total = qs * q;

    if(l% m != 0){
    s -= (m - (l % m)) * q;

 }   if(s % m == 0){
        ones = s / m;
    } else {
        ones = (s / m) + 1;
    }

    //cout << qs << " " << s << endl;

    if(s <= 0){
        cout << total << endl;
    } else {
        cout << total + ones << endl;
    }

    return 0;
}
