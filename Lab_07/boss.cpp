
#include <bits/stdc++.h>

using namespace std;


int main(){
    int n;

    cin >> n;
    
    int m, j, b;
    m = 0;
    j = 3;
    b = 1;
    
    while(!(m <= j && m >= (j - 2) % n)){
        m++;
        j += 2;
        b ++;
        m %= n;
        j %= n;
    }
    if(n <= 3){
        cout << 1 << endl;
    } else {
        cout << b << endl;
    }
    return 0;
}
