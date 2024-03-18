#include <bits/stdc++.h>
using namespace std;

pair<char, int>** dish;

bool trace(long long r, long long c, long long m, long long n, long long num){
    long long prevr = r;
    long long prevc = c;
    bool found = true;
    while(found){
        found = false;
        for(int i = -1; !found && i <= 1; i++){
            if(r + i >= 0 && r + i < m){
                for(int j = -1; !found && j <= 1; j++){
                    if((i == 0 && j == 0) || (prevr == r + i && prevc == c + j)){
                        continue;
                    }
                    if(c + j >= 0 && c + j < n){
                        if(dish[r + i][c + j].second == num){ 
                            return true;
                        } else if(dish[r + i][c + j].first == 'T'){
                            dish[r + i][c + j].second = num;
                            prevr = r;
                            prevc = c;
                            r += i;
                            c += j;
                            found = true;
                        }
                    }
                }
            }
        } 
    }
    return false;
}


int main(){
    long long m, n;    

    cin >> m >> n;

    
    dish = new pair<char, int>*[m];
    
    for (long long r = 0; r < m; r++){
        dish[r] = new pair<char, int>[n];
        for (long long c = 0; c < n; c++){
            char temp;
            cin >> temp;
            dish[r][c] = {temp, 0};
        }
    }

    long long count = 0;
    for (long long r = 0; r < m; r++){
        for (long long c = 0; c < n; c++){
            if(dish[r][c].first == 'T' && dish[r][c].second == 0){
                cout << "checking " << r << " " << c << endl;
                if(trace(r, c, m, n, count + 1)){
                    count++;
                    for (long long r = 0; r < m; r++){
                        for (long long c = 0; c < n; c++){
                            if(dish[r][c].first == 'T'){
                                cout << "." << dish[r][c].second;
                            } else {
                                cout << "...";
                            }
                            
                        }
                        cout << endl;
    }
                }
            } 
        }
    }

    

    
    return 0;
}
