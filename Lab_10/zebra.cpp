#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n;      
    cin >> n;

    long long total = 0;
    
    for(long long i = n-1; i >= 0; i--){
        char temp;
        cin >> temp;

        if(temp == 'O'){
            total += 1ll<<i;
        }
    }

    cout << total;
    
    return 0;
}
