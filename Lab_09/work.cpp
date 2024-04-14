#include <bits/stdc++.h>
using namespace std;

class mycomp{
public:
    bool operator() (const pair<long long, long long>& p1, const pair<long long, long long> p2) const{
        return p1.first < p2.first;
    }
};

int main(){
    long long n, m;

    cin >> n >> m;

    vector<pair<long long, long long>> ins;
    
    for (long long i = 0; i < n; i++){
        long long a, s;
        cin >> a >> s;
        ins.push_back({a,s});
    }

    sort(ins.begin(), ins.end(), mycomp());
    vector<pair<long long, long long>> comps;
    long long count = 0;
    comps.push_back({ins.at(0).first, ins.at(0).first + ins.at(0).second});
    for(long long i = 1; i < ins.size(); i++){
        bool found = false;
        for(long long j = 0; j < comps.size(); j++){
            if(comps.at(j).second + m < ins.at(i).first){
                comps.erase(comps.begin() + j);
                j--;
            } else if(comps.at(j).second < ins.at(i).first && comps.at(j).second + m < ins.at(i).first){
                count++;
                comps.at(j).first = ins.at(i).first;
                comps.at(j).second = ins.at(i).second;
                found = true;
                break;
            }
        }
        if(!found)
            comps.push_back({ins.at(i).first, ins.at(i).first + ins.at(i).second});
    }
    cout << count << endl;

    
    return 0;
}
