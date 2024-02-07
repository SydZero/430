#include <bits/stdc++.h>
using namespace std;

struct team {
    long long solved;
    long long penalty;
    bool above;
};

int main(){
    long long n;
    long long m;
    vector<team*> above;
    cin >> n >> m;
    team* teams[n];

    for(long long i = 0; i < n; i++){
        teams[i] = new team{0, 0, 0};
    }

    for(long long i = 0; i < m; i++){
        long long team, p;
        
        cin >> team >> p;
        team--;
        //check here

        teams[team]->solved++;
        teams[team]->penalty += p;

        //team 1 updated
        if(team == 0){
            //checking every item in above list
            for(long long j = 0; j < above.size(); j++){
                if(above.at(j)->solved < teams[0]->solved){
                    // cout << "FLAG8" << endl;
                    above.at(j)->above = false;
                    swap(above.at(j), above.at(above.size() - 1));
                    above.pop_back();
                    j--;
                } else if (above.at(j)->solved == teams[0]->solved && above.at(j)->penalty >= teams[0]->penalty){
                    //cout << "FLAG9" << endl;
                    above.at(j)->above = false;
                    swap(above.at(j), above.at(above.size() - 1));
                    above.pop_back();
                    j--;
                }
            }
        } else {
            // not team 1, only inserted when solved is equal with lower penalty or exactly 1 over, more than that its already there
            if(!teams[team]->above && teams[team]->solved == teams[0]->solved + 1){
                teams[team]->above = true;
                above.push_back(teams[team]);
            } else if(!teams[team]->above && teams[team]->solved == teams[0]->solved && teams[team]->penalty < teams[0]->penalty){
                teams[team]->above = true;
                above.push_back(teams[team]);
            }
        }
        cout << above.size() + 1 << endl;
    }
    return 0;
}