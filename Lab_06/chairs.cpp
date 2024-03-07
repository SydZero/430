#include <bits/stdc++.h>
using namespace std;

struct node{
    long long i;
    long long fav;

    node(long long f, long long ind){
        fav = f;
        i = ind;
    }
};

void print(vector<long long>& v){
    for(long long i : v){
        cout << i << " ";
    }
    cout << endl;
}

int main(){
    long long t;
    cin >> t;

    node* in[t];
    vector<long long> profs;
    for(long long i = 0; i < t; i++){
        long long temp;
        
        cin >> temp;
        profs.push_back(i);
        in[i] = new node(temp, i);
    }

    node* curr = in[0];
    long long move = 0;
    for(long long i = 0; i < t - 1; i++){
        //cout << curr->i << " " << curr->fav << endl;
        move = (move + curr->fav - 1) % (profs.size());
        //cout << "moving " << curr->i << ", remove: " << *(profs.begin()+move) << endl;
        
        profs.erase(profs.begin() + move);

        //print(profs);

        if(profs.begin() + move == profs.end()){
            curr = in[*(profs.begin())];
        } else {
            curr = in[*(profs.begin() + move)];
        }

        //cout << curr->i << " " << curr->fav << endl;
        
    }

    cout << profs.front() + 1 << endl;
      
    return 0;
}
