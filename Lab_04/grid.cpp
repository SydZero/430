#include <bits/stdc++.h>
using namespace std;

class mycomp{
public:
    bool operator() (const pair<int, int>& p1, const pair<int, int> p2) const{
        if(p1.first == p2.first){
            return p1.second < p2.second;
        }
        return p1.first < p2.first;
    }
};



int main(){
    long long n;
    cin >> n;

    long long num = n * n;

    char tree[n][n];
    
    string line;
    getline(cin, line);
    vector<pair<long long, long long>> points;
    for(int r = 0; r < n; r++){
        getline(cin, line);
        //cout << line << endl;
        for(int c = 0; c < n; c++){
            //cout << line.at(c) << endl;
            tree[r][c] = line.at(c);
            
            if(tree[r][c] == '.'){
                points.push_back(make_pair(r, c));
                tree[r][c] = 'X';
            }
        }
    }

    getline(cin, line);

    long long l = 0;
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < points.size(); j++){

            if(tree[points.at(j).first][points.at(j).second] != 'X'){
                cout << "invalid grille" << endl;
                return 0;
            }
            // cout << tree[points.at(j).first][points.at(j).second] << endl;
            tree[points.at(j).first][points.at(j).second] = line.at(l);
            
            l++;
            long long temp = points.at(j).first;
            //cout << points.at(j).first << " " << points.at(j).second;
            points.at(j).first = points.at(j).second;
            points.at(j).second = n - temp - 1;
            //cout << "->" << points.at(j).first << " " << points.at(j).second << endl;


        }

        sort(points.begin(), points.end(), mycomp());

        
    }
    string out = "";
    for(int r = 0; r < n; r++){
        for(int c = 0; c < n; c++){
            if(tree[r][c] == 'X'){
                cout << "invalid grille" << endl;
                return 0;
            }
            out += tree[r][c];
        }
    }
    cout << out << endl;

    return 0;
}
