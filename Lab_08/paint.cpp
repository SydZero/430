#include <bits/stdc++.h>
using namespace std;

int main(){

    int n, m;
    cin >> n >> m;

    set<int> sizes;

    long long sum = 0;

    for(int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        
        sizes.insert(temp);
    }

    for(int i = 0; i < m; i++){
        int temp;
        cin >> temp;

        int min = *sizes.lower_bound(temp);

        sum += min - temp;

    }

    cout << sum << endl;
    

    return 0;
}
