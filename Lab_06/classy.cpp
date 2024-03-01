#include <bits/stdc++.h>
using namespace std;

int main(){
    int t, n;
    
    cin >> t;

    for(int i = 0; i < t; i++){
        cin >> n;
        map<int, set<string>, greater<int>> coll;
        for(int j = 0; j < n; j++){
            int i = 0b1000000000000000000;
            int num = 0b10101010101010101010;
            string name, class_holder;
            char class_type;
            cin >> name;
            name.erase(name.size() - 1);
            while(i > 1){
                cin >> class_type;
                if(class_type == 'u'){
                    num = num + i * 0b11;
                } else if(class_type == 'm'){
                    num = num + i * 0b10;
                } else if(class_type == 'l'){
                    num = num + i * 0b01;
                }
                while(class_type != '-' && class_type != ' ' && class_type != 'c'){
                    cin >> class_type;
                }
                i /= 4;
                if(class_type == ' ' || class_type == 'c'){
                    break;
                }
            }
            while(i > 1){
                num = num + i * 0b10;
                i /= 4;
            }
            cin >> class_holder;
            coll[num].insert(name);
            //cout << name << " " << hex << num << endl;
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
