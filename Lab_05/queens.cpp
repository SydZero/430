#include <bits/stdc++.h>
using namespace std;

int main(){

    char tree[8][8];
    vector<pair<int, int>> queens;
    bool row[8] = {0, 0, 0, 0, 0, 0, 0, 0};
    bool col[8] = {0, 0, 0, 0, 0, 0, 0, 0};
    bool right[15] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    bool left[15] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    bool valid = true;

    int count = 0;

    for(int r = 0; r < 8; r++){
        for(int c = 0; c < 8; c++){
            cin >> tree[r][c];
            if(valid && tree[r][c] == '*'){
                count++;
                if(row[r] == true){
                    valid = false;
                } else {
                    row[r] = true;
                }

                if(col[c] == true){
                    valid = false;
                } else {
                    col[c] = true;
                }

                int ri = r - c + 7;
                int li = c + r;

                if(right[ri] == true){
                    valid = false;
                } else {
                    right[ri] = true;
                }

                if(left[li] == true){
                    valid = false;
                } else {
                    left[li] = true;
                }
    
            }
        }
    }

    if(valid && count == 8){
        cout << "valid" << endl;
    } else {
        cout << "invalid" << endl;
    }

    return 0;
}
