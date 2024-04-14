#include <bits/stdc++.h>
using namespace std;

struct team{
    long x;
    long y;
    bool valid;
    
    team(long x, long y): x(x), y(y), valid(true){}
    void print(){
        cout << "(" << x << ", " << y << ")";
    }
};

bool on_path(team a, team b, team c){
    // a.print();
    // cout << "->";
    // b.print();
    // cout << "->";
    // c.print();
    // cout << 0.5 * (a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y));
    // cout << endl;
    if(0.5 * (a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y)) == 0){
        if(a.x == b.x && b.x == c.x && ((a.y > b.y && b.y > c.y) || (a.y < b.y && b.y < c.y))){
            return true;
        } else if(a.y == b.y && b.y == c.y && ((a.x > b.x && b.x > c.x) || (a.x < b.x && b.x < c.x))){
            return true;
        } else if(a.x < b.x && b.x < c.x && a.y < b.y && b.y < c.y){
            return true;
        } else if(a.x > b.x && b.x > c.x && a.y > b.y && b.y > c.y){
            return true;
        } else if(a.x < b.x && b.x < c.x && a.y > b.y && b.y > c.y){
            return true;
        } else if(a.x > b.x && b.x > c.x && a.y < b.y && b.y < c.y){
            return true;
        } else {
            return false;
        }
    }
    return false;
}


int main(){
    long n, x, y;

    long a, b;

    cin >> n >> x >> y;
    team us = team(x, y);

    vector<team> teams;

    for(int i = 0; i < n; i++){
        cin >> a >> b;
        teams.push_back(team(a, b));
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; teams.at(i).valid && j < n; j++){
            if(i != j && on_path(teams.at(i), teams.at(j), us)){
                teams.at(i).valid = false;
            }
        }
    }

    int count = 0;

    for(int i = 0; i < n; i++){
        if(teams.at(i).valid){
            count++;
        }
    }
    cout << count << endl;


    return 0;
}
