#include <bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin >> n;

    set<int> numbers;
    set<int, greater<int>> dupes;

    bool found = false;
    

    for(int i = 1;i * i * i <= n; i++){
        for(int j = i; j * j * j <= n; j++){
            if((i * i * i) + (j * j * j) <= n){
                int sum = (i * i * i) + (j * j * j);
                if(numbers.find(sum) != numbers.end()){
                    found = true;
                    dupes.insert(sum);
                } else {
                    numbers.insert(sum);
                }
            }
        }
    }

    if(found){
        int maxm = 0;
        for(int s : dupes){
            maxm = max(s, maxm);
        }
        cout << maxm;
    } else {
        cout << "none" << endl;
    }

    return 0;
}
