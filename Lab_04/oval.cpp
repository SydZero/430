#include <bits/stdc++.h>
using namespace std;


int main(){
    long long n, k;

    cin >> n >> k;

    int pla[n];
    multimap<int, int, greater<int>> legs;

    for(int i = 0; i < n; i++){
        pla[i] = i;
    }

    for(int i = 0; i < k; i++){
        long long a, b;
        cin >> a >> b;
        legs.insert({b, a});
    }
    
    //start from bottom
    for(auto i = legs.begin(); i != legs.end(); i++){
        swap(pla[i->second], pla[i->second + 1]);
    }

    

    for(int i = 0; i != n; i++){
        cout << pla[i] << " ";
    }
    cout << endl;

    return 0;
}
