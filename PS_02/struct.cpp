#include <bits/stdc++.h>
using namespace std;

int main(){

    int n;
    
    int inst;
    int num;

    while(cin >> n){
        stack<int> sta;
        queue<int> q;
        priority_queue<int>  priq;
        bool stack = true;
        bool queue = true;
        bool pq = true;
        int j = 0;
        for(int i = 0; i < n; i++){
            cin >> inst >> num;
            if(inst == 1){
                sta.push(num);
                q.push(num);
                priq.emplace(num);
            } else {
                if(sta.empty() || (stack && sta.top() != num)){
                    stack = false;
                } else {
                    sta.pop();
                }
                if(q.empty() || (queue && q.front() != num)){
                    queue = false;
                } else {
                    q.pop();
                }
                if(priq.empty() || (pq   && priq.top() != num)){
                    pq = false;
                } else {
                    priq.pop();
                }
            }
        }
        if(stack && !queue && !pq){
            cout << "stack" << endl;
        } else if(!stack && queue && !pq){
            cout << "queue" << endl;
        } else if(!stack && !queue && pq){
            cout << "priority queue" << endl;
        } else if(!stack && !queue && !pq){
            cout << "impossible" << endl;
        } else {
            cout << "not sure" << endl;
        }
    }
}