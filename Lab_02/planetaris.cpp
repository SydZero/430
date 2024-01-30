#include <bits/stdc++.h>
using namespace std;



int main(){
    long long n, a;
    cin >> n >> a;
    long long temp;
    long long count = 0;
    vector<int> ships(n);
    for(long long i = 0; i< n; i++){
        cin >> ships.at(i);
        
    }

    sort(ships.begin(), ships.end());

    for(long long i = 0; i < n; i++){
        //cout << ships.at(i) << " " << a << endl;
        if(ships.at(i) + 1 <= a){
            count++;
            a = a - (ships.at(i) + 1);
            //cout << "can" << endl;
        } else {
            //cout << "cannot" << endl;
            break;
        }
    }
    cout << count << endl;

    return 0;
}