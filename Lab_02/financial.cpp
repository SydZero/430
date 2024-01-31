#include <bits/stdc++.h>
using namespace std;

//determine how many days to make money
// (c/p) + 1 - (int division)
// 1: add first profitable dayamount for each investment from that day
//  how many more days to meet M

struct investment{
    long long cost;
    long long profit;
    long long days;

    investment(){
        cost = 0;
        profit = 0;
        days = 0;
    }
    investment(long long cost1, long long profit1){
        cost = cost1;
        profit = profit1;
        days = (cost / profit) + 1;
    }
};

class mycomp{
public:
    bool operator() (const investment& inv1, const investment&inv2){
        return inv1.days > inv2.days;
    }
};

int main(){
    long long n, M, p, c;
    cin >> n >> M;
    priority_queue<investment, vector<investment>, mycomp> investments;

    for(long long i = 0; i < n; i++){
        cin >> p >> c;
        investments.push(investment(c, p));
    }
    investment inv = investments.top();
    long long tot_cost = M + investments.top().cost;
    long long tot_profit = investments.top().profit;
    long long min_days = ((tot_cost + inv.cost) / (tot_profit + inv.profit)) + 1;
    investments.pop();
    for(long long i = 1; i < n; i++){
        inv = investments.top();
        if(((tot_cost + inv.cost) / (tot_profit + inv.profit)) + 1 < min_days){
            min_days = ((tot_cost + inv.cost) / (tot_profit + inv.profit)) + 1;
            tot_cost += inv.cost;
            tot_profit += inv.profit;
        }
    }

    cout << min_days << endl;

    return 0;
}
