#include <bits/stdc++.h>
using namespace std;

int main(){
    long long l, d, n;

    cin >> l >> d >> n;

    vector<long long> birds;
    
    for(int i = 0; i < n; i++){
        long long temp;
        cin >> temp;
        birds.push_back(temp);
    }
    // cout << "FLAG 1" << endl;

    long long sum = 0;

    if(birds.size() >= 1){
        // cout << "FLAG 2" << endl;
        sort(birds.begin(), birds.end(), less<long long>());
        if(birds.at(0) - (6 + d) >= 0){
            sum++;
            sum += (birds.at(0) - (6 + d)) / d;
        }
        // cout << "FLAG 3" << endl;
        if(l - birds.at(birds.size() - 1) - (6 + d) >= 0){
            sum++;
            sum += (l - birds.at(birds.size() - 1) - (6 + d)) / d;
        }
        // cout << "FLAG 4" << endl;
    
    
        for(int i = 0; i < birds.size() - 1; i++){
            // cout << birds.at(i + 1)<< " " <<  birds.at(i) << endl;
            if(birds.at(i + 1) - birds.at(i) - (2 * d) >= 0){
                sum++;
                sum += (birds.at(i + 1) - birds.at(i) - (2 * d)) / d;
            }
        }
    } else {
        if(l - (12) >= 0){
            sum++;
            sum += (l - 12) / d;
        }
    }


    cout << sum << endl;

    return 0;
}
