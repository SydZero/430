#include <bits/stdc++.h>
using namespace std;



int main(){
 
    long long n;
    string people;
    cin >> n >> people;

    long long m = 0;
    long long w = 0;
    long long count = 0;

    for(long long i = 0; i < people.length(); i++){
        //cout << people << endl;
        if(abs(m - w) < n){
            if(people.at(i) == 'M'){
                m++;
            } else {
                w++;
            }
        } else if(m > w){
            if(people.at(i) == 'W'){
                w++;
            } else if(i < people.length() - 1 && people.at(i + 1) == 'W'){
                people.at(i) = 'W';
                people.at(i + 1) = 'M';
                i--;
                continue;
            } else {
                break;
            }
        } else if(m < w){
            if(people.at(i) == 'M'){
                m++;
            } else if(i < people.length() - 1 && people.at(i + 1) == 'M'){
                people.at(i) = 'M';
                people.at(i + 1) = 'W';
                i--;
                continue;
            } else {
                break;
            }
        }
        count++;
    }
    cout << count << endl;
            
    return 0;
}
