#include <bits/stdc++.h>
using namespace std;

long long n, k;
long long total = 0;
long long rem = 0;
long long capacity;
long long prev_dist = -1;

void update(pair<int, int>& curr){
    int num_runs = 0;
    curr.first = abs(curr.first);
    if(capacity == k){
        num_runs++;
    }
    if(capacity > curr.second){
        capacity -= curr.second;
        total += num_runs * 2 * curr.first;
        return;
    } else {
        curr.second -= capacity;
    }

    capacity = k;
    if(curr.second > 0){
        num_runs += abs(curr.second / k);
        rem = abs(curr.second % k);
        if(rem != 0){
            num_runs++;
        }
        capacity = k - rem;
    }        
    total += num_runs * 2 * curr.first;
    prev_dist = curr.first;

}

int main(){
    
    cin >> n >> k;
    capacity = k;
    
    vector<pair<int, int>> negative;
    vector<pair<int, int>> positive;

    for (long long i = 0; i < n; i++){
        long long distance, letters;
        cin >> distance >> letters;
        
        if(distance < 0){
            negative.push_back({distance, letters});
        } else {
            positive.push_back({distance, letters});
        } 
    }

    for(int i = 0; i < negative.size(); i++){
        pair<int, int> curr = negative.at(i);

        update(curr);
    }
    prev_dist = 0;
    capacity = k;

    for(int i = positive.size() - 1; i >= 0; i--){
        pair<int, int> curr = positive.at(i);
        update(curr);
    }

    cout << total << endl;
    return 0;
}
