#include <bits/stdc++.h>
using namespace std;

struct team {
    long long solved;
    long long penalty;
};

int main(){
    long long n;
    long long m;
    vector<team*> above;
    cin >> n >> m;
    team* teams[n];

    for(long long i = 0; i < n; i++){
        teams[i] = new team{0, 0};
    }

    for(long long i = 0; i < m; i++){
        long long team, p;
        
        cin >> team >> p;
        team--;
        teams[team]->solved++;
        teams[team]->penalty += p;
        // cout << "FLAG1" << endl;
        if(team == 0){
            // cout << "FLAG2" << endl;
            for(long long j = 0; j < above.size(); j++){
                if(above.at(j)->solved < teams[0]->solved){
                    // cout << "FLAG8" << endl;
                    swap(above.at(j), above.at(above.size() - 1));
                    above.pop_back();
                    j--;
                } else if (above.at(j)->solved == teams[0]->solved && above.at(j)->penalty > teams[0]->penalty){
                    //cout << "FLAG9" << endl;
                    swap(above.at(j), above.at(above.size() - 1));
                    above.pop_back();
                    j--;
                }
                // cout << "FLAG5" << endl;
            }
        } else {
            // cout << "FLAG3" << endl;
            if(teams[team]->solved == teams[0]->solved + 1){
                above.push_back(teams[team]);
            } else if(teams[team]->solved == teams[0]->solved && teams[team]->penalty < teams[0]->penalty){
                above.push_back(teams[team]);
            }
            //cout << "FLAG6" << endl;
        }
        cout << above.size() + 1 << endl;
        //cout << "FLAG7" << endl;

    }
    return 0;
}