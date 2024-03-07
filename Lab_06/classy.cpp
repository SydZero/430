#include <bits/stdc++.h>
using namespace std;

int main(){
    long long t, n;
    cin >> t;

    for(long long i = 0; i < t; i++){
        cin >> n;
        map<long long, set<string>, less<long long>> coll;
        for(long long j = 0; j < n; j++){
            long long i = 100000000000;
            long long num = 0;
            string name, class_holder;
            char class_type;
            cin >> name;
            name.erase(name.size() - 1);
            while(i >= 1){
                cin >> class_type;
                if(class_type == 'u'){
                    num = num + i * 3;
                } else if(class_type == 'm'){
                    num = num + i * 2;
                } else if(class_type == 'l'){
                    num = num + i * 1;
                }
                // cout << num << endl;
                while(class_type != '-' && class_type != ' ' && class_type != 'c'){
                    cin >> class_type;
                }
                i = i / 10;
                if((class_type == ' ' || class_type == 'c')){
                    while(i >= 1){
                        num += 2 * i;
                        i /= 10;
                    }
                    break;
                }
            }
            cin >> class_holder;
            // cout << name << " " << -1 * num << endl;
            coll[num * -1].insert(name);
        }
        for(auto namelist: coll){
            for(auto namey: namelist.second){
                cout << namey << endl;
            }
        }
        cout << "==============================" << endl;
    }

      
    return 0;
}
