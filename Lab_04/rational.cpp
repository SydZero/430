#include <bits/stdc++.h>
using namespace std;


int main(){
    long long P;

    cin >> P;

    for(int i = 0; i < P; i++){
        long long k, p, q, A;
        char slash;
        cin >> k >> p >> slash >> q;
        long long num = p;
        long long den = q;
        A = p / q;
        num = num % den;
        den = den - num;
        num = num + den;
        den = den + num * A;
        cout << k << " " << num << "/" << den << endl;
    }
    return 0;
}
