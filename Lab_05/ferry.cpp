#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n, m, lol;

    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> lol >> m;

        lol *= 100;

        vector<long long> left;
        vector<long long> right;

        long double centi;
        string side;

        
        for(int j = 0; j < m; j ++){
            cin >> centi >> side;
            if(side == "left"){
                left.push_back(centi);
            } else {
                right.push_back(centi);
            }
        }

        long long from_left = 0;
        long long from_right = 0;
        long long l = 0;
        long long r = 0;

        while(l < left.size() || r < right.size()){
            long long sum = 0;
            if(l < left.size()){
                while(sum + left[l] <= lol){
                    sum += left[l];
                    l++;
                }
            }            
            if(sum > 0 || r < right.size()){
                from_left++;
            }
            sum = 0;
            if(r < right.size()){
                while(sum + right[r] <= lol){
                    sum += right[r];
                    r++;
                }
            }
            if(sum > 0 || l < left.size()){
                from_right++;
            }
            
            
        }
        cout << from_left + from_right << endl;

    }

    return 0;
}
