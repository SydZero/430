#include <bits/stdc++.h>
using namespace std;

int hashy(string str){

    int hash = 0;
    for(int i = 0; i < str.size(); i++){
        hash = hash ^ str.at(i);
    }

    return hash;
}


int main(){
    string nstr;
    while (true){
        getline(cin, nstr);
        int n = stoi(nstr);
        if(n == 0){
            break;
        }
        int collisions = 0;
        int unique = 0;
        vector<string> strs;
        map<int, pair<set<string>, int>> mapy;
        map<string, int> words;
        for(int i = 0; i < n; i++){
            string line;
            getline(cin, line);

            strs.push_back(line);
            int h = hashy(strs[i]);

            auto find = mapy.find(h);
            if(mapy.empty() || find == mapy.end()){
                mapy[h].first.insert(strs.at(i));
                words.insert({strs.at(i), 1});
                unique++;
                
            } else {
                int found = false;
                for(const string& exists : mapy[h].first){
                    if(exists == strs.at(i)){
                        found = true;
                
                        collisions += mapy[h].second - words[strs.at(i)];
                        words[strs.at(i)]++;
                        break;
                    }
                }
                if(!found){
                    collisions += mapy[h].second;
                    unique++;

                    mapy[h].first.insert(strs.at(i));
                    words[strs.at(i)] = 1;
                }
            }
            mapy[h].second++;
        }
        cout << unique << " " << collisions << endl;
    }

    return 0;
}
