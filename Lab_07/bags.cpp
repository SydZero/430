#include <bits/stdc++.h>
using namespace std;

void print(vector<bool>& v){
    for(long long i = 0; i < v.size(); i++){
        cout << v.at(i) << " ";
    }
    cout << endl;
}

struct bag{
    vector<long long> baggy;

    bag(long long n){
        baggy.push_back(n);
    }

    bool canfit(long long n){
        if(n < baggy.at(baggy.size()-1)){
            return true;
        }
        return false;
    }
};


int main(){
    long long num;
    
    while(cin >> num){
        if(num == 0){break;}
    vector<long long> vals;
    vector<bag> bags;

    for(long long i = 0; i < num; i++){  
        long long num1;
        cin >> num1;
        vals.push_back(num1);
    }

    sort(vals.begin(), vals.end(), greater<long long>());

    for(long long i = 0; i < num; i++){  
        if(bags.empty()){
            bags.push_back(vals.at(i));
        } else {
            bool inserted = false;
            for(int j = 0; j < bags.size(); j++){
                if(bags.at(j).canfit(vals.at(i))){
                    bags.at(j).baggy.push_back(vals.at(i));
                    inserted = true;
                    break;
                }
            }
            if(!inserted){
                bags.push_back(bag(vals.at(i)));
            }
        }
    }

    cout << bags.size() << endl;
    for(bag b : bags){
        for(long long i : b.baggy){
            cout << i << " ";
        }
        cout << endl;
    }

    }
      
    return 0;
}
