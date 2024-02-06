#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    map<int, pair<int, bool>, greater<int>> guests;
    map<int, pair<int, bool>, greater<int>>::iterator it;
    for(int i = 0; i < n; i++){
        int lang;
        cin >> lang;
        it = guests.find(lang);
        if(it != guests.end()){
            guests[lang] = {it->second.first, true};
        } else {
            guests[lang]= {i+1, false};
        }
    }

    it = guests.begin();
    bool found = false;
    while(it != guests.end()){
        //cout << it->first << " " << it->second.second << endl;
        if(it->second.second == 1){
            it++;
        } else {
            cout << it->second.first << endl;
            found = true;
            it++;
            break;
        }
    }

    if(!found)
        cout << "none" << endl;
    


    return 0;
}
