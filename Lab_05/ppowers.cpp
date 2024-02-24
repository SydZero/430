#include <bits/stdc++.h>
using namespace std;

int main(){
    long long x;
    while(true){
        cin >> x;
        if(x == 0){
            break;
        }
        bool found = false;

        if(x > 0){
            for(long long i = 32; i >= 2; i--){
                double n = pow(x, 1.0/i);
                n += .000000000001;
                int nint = n;
                // cout << i << " " << n << " " << nint << endl;
                if(pow(nint, i) == x){
                    cout << i << endl;
                    found = true;
                    break;
                }
            }
        } else {
            for(long long i = 31; i >= 3; i-=2){
                double n = pow(abs(x), 1.0/i);
                n += .000000000001;
                int nint = n;
                //cout << x << ": " << i << " " << n << " " << nint << endl;
                if(pow(nint, i) == x * -1){
                    cout << i << endl;
                    found = true;
                    break;
                }
            }
        }
        if(!found){
            cout << 1 << endl;
        }
    }      
    return 0;
}
