#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n, k;

    cin >> n;
    long long world[n];
    for (long long i = 0; i < n; i++){
        cin >> world[i];
    }

    long long sum = 0;
    long long curr = world[n - 1];
    bool valid = true;

    for (long long i = n - 1; i >= 0; i--){
        if(world[i] > curr){
            sum += world[i] - curr;
            world[i] = curr;
        }
        
        curr = world[i] - 1;
        if(world[i] < 0){
            valid = false;
            break;
        }
    }

    if(valid){
        cout << sum << endl;
    } else {
        cout << 1 << endl;
    }
    
    return 0;
}
