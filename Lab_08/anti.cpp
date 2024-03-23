#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    while (true){
        cin >> n;
        if(n == 0){
            break;
        }
        map<int, int> order;
        bool invalid = false;
        char colon;
        cin >> colon;
        for(int i = 0; i < n; i++){
            int temp;
            cin >> temp;
            order.insert({temp, i});
            auto curr = order.find(temp);
            if(curr == order.begin()){
                continue;
            }
            auto curr1 = --curr;
            if(curr1 == order.begin()){
                continue;
            }
            auto curr2 = --curr1;

            cout << (*curr2).second << " " << (*curr1).second << " " <<  (*curr).second << endl;
            if((*curr2).second < (*curr1).second && (*curr1).second < (*curr).second){
                invalid = true;
            }
        }
        if(!invalid){
            cout << "yes" << endl;
        } else {
            cout << "no" << endl;
        }
    }

    return 0;
}
