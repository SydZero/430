#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n;
    long long num_socks;
    long long moves = 0;
    cin >> n;
    num_socks = 2 * n;

    stack<long long> aux;
    stack<long long> og;
    
    for(long long i = 0; i < num_socks; i++){
        long long lang;
        cin >> lang;
        og.push(lang);
    }

    while(!og.empty()){
        // cout << og.size() << " " <<  aux.size() << endl;
        // if(!aux.empty()){
        //     cout << og.top() << " " <<  aux.top() << endl;
        // } else {
        //     cout << og.top() << endl;
        // }
        if(!aux.empty() && og.top() == aux.top()){
            og.pop();
            aux.pop();
        } else {
            aux.push(og.top());
            og.pop();
            
        } 
        moves++;
    }
    if(aux.empty()){
        cout << moves << endl;
    } else {
        cout << "impossible" << endl;
    }

    return 0;
}
