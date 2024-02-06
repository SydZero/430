#include <bits/stdc++.h>
using namespace std;

int main(){
    int b, k, g;
    cin >> b >>k >> g;

    b--;
    int gps = k/g;
    if(b % gps == 0){
        cout << (b)/gps << endl;
    } else {
        cout << ((b)/gps) + 1 << endl;
    }


    return 0;
}
