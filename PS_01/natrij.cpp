#include <bits/stdc++.h>
using namespace std;

int main(){

    int hours, mins, secs;
    int hours1, mins1, secs1;
    int hours2, mins2, secs2;
    char colon;
    cin >> hours1 >> colon >> mins1 >> colon >> secs1;
    cin >> hours2 >> colon >> mins2 >> colon >> secs2;
    
    if(hours2 <= hours1){
        if(hours2 == hours1 && mins2 <= mins1){
            if(mins2 == mins1 && secs2 <= secs1){
                hours2 += 24;
            } else {
                hours2 += 24;
            }
        } else {
            hours2 += 24;
        }
    }

    //hours
    hours = hours2 - hours1;
    mins = mins2 - mins1;
    secs = secs2 - secs1;
    
    if(secs < 0){
        secs += 60;
        mins -= 1;
    }
    if(mins < 0){
        mins += 60;
        hours -= 1;
    }
    if(hours < 0){
        hours += 24;
    }



    if(hours == mins && mins == secs && secs == 0){
        hours = 24;
    }

    //output
    if(hours < 10){
        cout << "0";
    }
    cout << hours << ":";
    
    if(mins < 10){
        cout << "0";
    }
    cout << mins << ":";
    if(secs < 10){
        cout << "0";
    }
    cout << secs << endl;
    return 0;
}