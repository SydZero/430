#include <bits/stdc++.h>
using namespace std;

class mycomp{
public:
    bool operator() (const pair<int, int>& p1, const pair<int, int> p2) const{
        if(p1.first == p2.first){
            return p1.second > p2.second;
        }
        return p1.first > p2.first;
    }
};

int main(){

    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    int e, g, x;

    cin >> n;
    multiset<pair<long long, long long>, mycomp> quests;
    string instruction; 
    for(long long i = 0; i < n; i++){
        cin >> instruction;
        if(instruction == "add"){
            cin >> e >> g;
            quests.insert({e, g});
        } else if(instruction == "query"){
            long long gold = 0;
            cin >> x;
            multiset<pair<long long, long long>, mycomp>::iterator i = quests.lower_bound({x, LONG_LONG_MAX});
            while(x > 0 && i != quests.end()){
                //cout << endl << "Query: energy left=" << x << " energyreq=" << i->first << " gold=" << i->second << " goldtot=" << gold <<endl;
                x -= i->first;
                gold += i->second;
                quests.erase(i);
                i = quests.lower_bound({x, LONG_LONG_MAX});
            }
            cout << gold << endl;
        }
    }


    return 0;
}