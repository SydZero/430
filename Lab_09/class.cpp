#include <bits/stdc++.h>
using namespace std;

class mycomp{
public:
    bool operator() (const pair<long long, long long>& p1, const pair<long long, long long> p2) const{
        return p1.first < p2.first;
    }
};

int main(){
    long long n, k;

    cin >> n >> k;
    vector<pair<long long, long long>> activities;
    long long classrooms[k]{0};
    for (long long i = 0; i < n; i++){
        long long s, f;
        cin >> s >> f;

        activities.push_back({s, f});
           
    }

    sort(activities.begin(), activities.end(), mycomp());
    int count = 0;
    for(long long i = 0; i < activities.size(); i++){
        long long min_class = INT32_MAX;
        long long min_time = INT32_MAX;
        for(long long j = 0; j < k; j++){
            if(classrooms[j] < activities.at(i).first && classrooms[j] < min_time){
                //cout << classrooms[j] << " " << activities.at(i).first << endl;
                min_time = classrooms[j];
                min_class = j;
            }
        }
        if(min_class != INT32_MAX){
            classrooms[min_class] = activities.at(i).second;
            count++;
        }
    }

    cout << count << endl;
    
    
    return 0;
}
