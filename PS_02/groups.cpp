#include <bits/stdc++.h>
using namespace std;

void print_set(set<string> vals){
    for(string str: vals){
        cout << str << " " ;
    }
    cout << endl;
}

set<string>& parse_argument(unordered_map<string, set<string>>& groups, stringstream& line){
    string token;
    line >> token;
    set<string> arg1 = parse_argument(groups, line);
    set<string> arg2 = parse_argument(groups, line);
    set<string> ret_set;
    if(token == "union"){
        return set_union(arg1.begin(), arg1.end(), arg2.begin(), arg2.end(), ret_set.begin());
    } else if(token == "intersection"){
        return set_intersection();
    } else if(token == "difference"){
        return set_difference();
    }
    return groups[token];
}


int main(){

    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    unordered_map<string, set<string>> groups;
    string line;
    string token;
    string gname;
    int num;
    stack<string> instructions;
    stack<string> content;

    while(getline(cin, line)){
        stringstream strstm(line);
        strstm >> token;
        if(token == "group"){
            strstm >> gname >> num;
            for(int i = 0; i < num; i++){
                string temp;
                strstm >> temp;
                groups[gname].emplace(temp);
            }
        } else {
            set<string> done = parse_argument(groups, strstm);
            print_set(done);
        }
    }


    return 0;
}