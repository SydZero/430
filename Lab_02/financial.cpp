#include <bits/stdc++.h>
using namespace std;

struct investment{
    long long cost;
    long long profit;
    long long days_even;

    investment(){
        cost = 0;
        profit = 0;
        days_even = 0;
    }

    investment(long long cost1, long long profit1){
        cost = cost1;
        profit = profit1;
        days_even = (cost / profit) + 1;
    }
};

class mycomp{
public:
    bool operator() (const investment& inv1, const investment&inv2) const{
        return inv1.days_even < inv2.days_even;
    }
};

int main(){
    long long n, M, p, c;
    cin >> n >> M;

    vector<investment> investments;
    
    for(long long i = 0; i < n; i++){
        cin >> p >> c;
        investments.push_back(investment(c, p));
    }
    sort(investments.begin(), investments.end(), mycomp());

    long long total_cost = 0;
    long long daily_profit = 0;
    long long min_days = LONG_LONG_MAX;
    for(int i = 0; i < investments.size(); i++){
        investment curr = investments.at(i);
        long long curr_days = ceil(1.0 * (M + total_cost + curr.cost) / (daily_profit + curr.profit));
        
        //cout << "Investment: cost=" << curr.cost << " profit=" << curr.profit << " currdays=" << curr_days << " mindays=" << min_days << endl;
        if(curr_days <= min_days){
            min_days = curr_days;
            total_cost += curr.cost;
            daily_profit += curr.profit;
            //cout << "    new min_days:" << min_days << endl;
        }
    }

    cout << min_days << endl;

    return 0;
}
