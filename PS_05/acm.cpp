#include <bits/stdc++.h>
using namespace std;

struct minion{
    int min;
    int max;

    minion(int l, int u){
        min = l;
        max = u;
    }
};

class mycomp{
public:
    bool operator() (const minion& p1, const minion& p2) const{
        int range1 = p1.max - p1.min;
        int range2 = p2.max - p2.min;
        return range1 < range2;
    }
};



struct room{
    int min;
    int max;

    room(minion m){
        min = m.min;
        max = m.max;
    }

    bool fits(minion m){
        int L = m.min;
        int U = m.max;
        // cout << "FLAG 1" << endl;
        //up inside
        if(min <= U && U <= max && L <= min){
            // cout << "FLAG 2: " << L << " " << min << " " << U << " " << max << endl;
            max = U;
            return true;
        }
        //down inside
        if(L <= max && L >= min && U >= max){
            // cout << "FLAG 3" << endl;
            min = L;
            return true;
        }
        //both inside
        if(L >= min && U <= max){
            // cout << "FLAG 4" << endl;
            min = L;
            max = U;
            return true;
        }
        // both outside
        if(L <= min && U >= max){
            // cout << "FLAG 6" << endl;
            return true;
        }
        // cout << "FLAG 7" << endl;
        return false;
        
    }
};

void print(room r){
    cout << r.min << " " << r.max << endl;
}

void print(vector<room> rooms){
    cout << "-------------" << endl;
    for(int i = 0; i < rooms.size(); i++){
        print(rooms.at(i));
    }
    cout << "-------------" << endl;
}

int main(){
    long long n;

    cin >> n;
    multimap<int, int, mycomp> temps;
    vector<minion> minions;
    vector<room> rooms;

    for (long long i = 0; i < n; i++){
        long long L, U;
        cin >> L >> U;
        minions.push_back(minion(L, U));
    }
    sort(minions.begin(), minions.end(), mycomp());
    for(int i = 0; i < minions.size(); i++){
        // cout << minions.at(i).min << " " << minions.at(i).max << endl;
        bool found = false;
        for(int j = 0; j < rooms.size(); j++){
            if(rooms.at(j).fits(minions.at(i))){
                found = true;
                break;
            }
        }
        if(!found){
            room temp(minions.at(i));
            rooms.push_back(temp);
        }
        //print(rooms);
    }
    cout << rooms.size() << endl;

    
    
    return 0;
}
