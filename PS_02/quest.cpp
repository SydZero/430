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
    multiset<pair<int, int>, mycomp> quests;
    string instruction; 
    for(int i = 0; i < n; i++){
        cin >> instruction;
        if(instruction == "add"){
            cin >> e >> g;
            quests.insert({e, g});
        } else if(instruction == "query"){
            int gold = 0;
            cin >> x;
            multiset<pair<int, int>, mycomp>::iterator e = quests.begin();
            bool del = false;
            for(auto i = quests.begin(); i != quests.end(); i++){
                if(del)
                    quests.erase(e);
                del = false;
                //cout << endl << "Query: energy left=" << x << " energyreq=" << i->first << " gold=" << i->second << " goldtot=" << gold <<endl;
                if(i->first <= x){ 
                    x -= i->first;
                    gold += i->second;
                    del = true;
                    e = i;
                }
            }
            if(del)
                quests.erase(e);
            cout << gold << endl;
        }
    }


    return 0;
}