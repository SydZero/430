#include <bits/stdc++.h>
using namespace std;

//heap - priority queue
//size of top part = size of bottom + {0, 1}
//pull med from top
    // if top too small
        // move biggest one from bottom to top
//insert into whichever side then balance

int main(){

    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    priority_queue<long long, vector<long long>, greater<long long>> minq;
    priority_queue<long long> maxq;
    string str;

    while(getline(cin, str)){
        if(str.at(0) != '#'){
            long long curr = stoll(str);
            if(maxq.size() == 0 || curr <= maxq.top()){
                maxq.push(curr);
            } else {
                minq.push(curr);
            }
        } else {
            if(maxq.size() != 0 && maxq.size() > minq.size()){
                cout << maxq.top() << endl;
                maxq.pop();
            } else if(minq.size() != 0){
                cout << minq.top() << endl;
                minq.pop();
            }
        }
        if(maxq.size() < minq.size()){
            maxq.push(minq.top());
            minq.pop();
        } else if(maxq.size() > minq.size() + 1){
            minq.push(maxq.top());
            maxq.pop();
        }
    }
            
    return 0;
}
