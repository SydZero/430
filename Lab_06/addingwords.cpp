#include <bits/stdc++.h>
using namespace std;

int main(){
    string ins;
    map<string, int> word;
    map<int, string> num;
    
    while(cin >> ins){
        if(ins == "def"){
            string newword;
            int newint;
            cin >> newword >> newint;
            map<string, int>::iterator rm = word.find(newword);
            if(rm != word.end()){
                num.erase(num.find(rm->second));
            }
            word[newword] = newint;
            num[newint] = newword;
        } else if(ins == "calc"){
            string val;
            char op;
            bool valid = true;
            cin >> val >> op;
            cout << val << " " << op << " ";
            int final_num = 0;
            int change = 1;
            while(op != '='){
                if(word.find(val) != word.end()){
                    final_num += change * word[val];
                } else {
                    valid = false;
                }
            
                if(op == '-'){
                    change = -1;
                } else {
                    change = 1;
                }

                cin >> val >> op;
                cout << val << " " << op << " ";
            }
            if(word.find(val) != word.end()){
                final_num += change * word[val];
            } else {
                valid = false;
            }
            if(valid && num.find(final_num) != num.end()){
                cout << num[final_num] << endl;
            } else {
                cout << "unknown" << endl;
            }
            
        } else if(ins == "clear"){
            word.clear();
            num.clear();
        }
    }

      
    return 0;
}
