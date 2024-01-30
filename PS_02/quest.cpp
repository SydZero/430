#include <bits/stdc++.h>
using namespace std;

int main(){

    // std::ios::sync_with_stdio(false);
    
    // cin.tie(NULL);
    // cout.tie(NULL);

    int n;
    int e, g, x;

    cin >> n;
    priority_queue<pair<int, int>> quests;
    string instruction; 
    for(int i = 0; i < n; i++){
        cin >> instruction;
        if(instruction == "add"){
            cin >> e >> g;
            quests.emplace(make_pair(e, g));
        } else if(instruction == "query"){
            int gold = 0;
            cin >> x;
            auto curr = quests.
            while(curr != quests){
                if(curr.first <= x){
                    x -= curr.first;
                    gold += curr.second;
                    cout << "quest: " << curr.first << " " << curr.second << endl;
                    quests.pop();
                    curr = quests.top();
                }
                curr = curr
            }
            cout << "gold: " << gold << endl;
        }
    }


    return 0;
}