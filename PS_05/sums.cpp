#include <bits/stdc++.h>
using namespace std;

void powerset(vector<int>& nums){
    long long pow_set_size = pow(2, nums.size()); 
    map<long long, set<long long>*> combos;

    for (long long i = 0; i < pow_set_size; i++) { 
        long long sum = 0;
        set<long long>* s = new set<long long>();
        for (long long j = 0; j < nums.size(); j++) { 
            if (i & (1 << j)) {
                sum += nums.at(j);
                s->insert(nums.at(j));
            }
        } 
        auto found = combos.find(sum);
        if(found != combos.end()){
            for(long long num : *(found->second)){
                cout << num << " ";
            }
            cout << endl;
            for(long long num : *(s)){
                cout << num << " ";
            }
            cout << endl;
            break;
        } else {
            combos.insert({sum, s});
        }
    }
}


int main(){
    long long t;

    cin >> t;

    for (long long i = 0; i < t; i++){
        long long n;
        cin >> n;
        vector<int> nums;
        cout << "Case #" << i + 1 << ":" << endl;
        for (long long j = 0; j < n; j++){
            int temp;
            cin >> temp;
            nums.push_back(temp);
        }
        sort(nums.begin(), nums.end(), less<int>());
        powerset(nums);
    }
      
    return 0;
}
