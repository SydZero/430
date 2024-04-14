#include <bits/stdc++.h>
using namespace std;

class mycomp{
public:
    bool operator() (const pair<long long, long long>& p1, const pair<long long, long long> p2) const{
        return p1.first < p2.first;
    }
};

int main(){
    long long D;

    cin >> D;
    bool found = false;

    for(long long i = 0; i < D && !found; i++){
        for(long long j = i; i * i + D >= j * j && !found; j++){
            if((j * j) - (i * i) == D){
                cout << i << " " << j << endl;
                found = true;
            }
        }
    }

    if(!found){
        cout << "impossible" << endl;
    }
    return 0;
}
