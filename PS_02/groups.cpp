#include <bits/stdc++.h>
using namespace std;

void print_set(set<string> vals){
    if(vals.empty()){
        return;
    }
    for(string str: vals){
        cout << str << " " ;
    }
    cout << endl;
}

void print(string out){
    cout << out;
}

void parse_argument(unordered_map<string, set<string>>& groups, stringstream& line, set<string>& ret_set){
    string token;
    if(line >> token){
        // print("Token: " + token + "\n");
        if(token == "group"){
            string gname;
            int num;
            line >> gname >> num;
            for(int i = 0; i < num; i++){
                string temp;
                line >> temp;
                groups[gname].insert(temp);
            }
            // print("Group Created \"" + gname + "\": ");
        } else{
            if(token == "union"){  
                set<string> arg1;
                parse_argument(groups, line, arg1);
                set<string> arg2;
                parse_argument(groups, line, arg2);
                set_union(arg1.begin(), arg1.end(), arg2.begin(), arg2.end(), inserter(ret_set, ret_set.begin()));
            } else if(token == "intersection"){
                set<string> arg1;
                parse_argument(groups, line, arg1);
                set<string> arg2;
                parse_argument(groups, line, arg2);
                // print("  INTERSECTION:");
                set_intersection(arg1.begin(), arg1.end(), arg2.begin(), arg2.end(), inserter(ret_set, ret_set.begin()));
            } else if(token == "difference"){
                set<string> arg1;
                parse_argument(groups, line, arg1);
                set<string> arg2;
                parse_argument(groups, line, arg2);
                // print("  DIFFERENCE:");
                set_difference(arg1.begin(), arg1.end(), arg2.begin(), arg2.end(), inserter(ret_set, ret_set.begin()));
            } else {
                // print("  BASE CASE: ");
                ret_set = groups[token];
            }
        }
    
        // print_set(ret_set);
    }
}


int main(){
    // std::ios::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);

    unordered_map<string, set<string>> groups;
    string line;
    string token;

    while(getline(cin, line)){
        stringstream strstm(line);
        set<string> done;
        parse_argument(groups, strstm, done);

        // print("Done: ");
        print_set(done);
    }
    return 0;
}