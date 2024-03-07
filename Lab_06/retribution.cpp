#include <bits/stdc++.h>
using namespace std;

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long n, m, p;
    cin >> n >> m >> p;

    vector<long long> judges, tar, feathers;

    priority_queue<long long> judges_tar;
    priority_queue<long long> judges_feathers;

    for(int i = 0; i < n; i++){
        long long temp;
        cin >> temp;
        judges.push_back(temp);
    }

    for(int i = 0; i < m; i++){
        long long temp;
        cin >> temp;
        tar.push_back(temp);
    }
    for(int i = 0; i < p; i++){
        long long temp;
        cin >> temp;
        feathers.push_back(temp);
    }
    

      
    return 0;
}