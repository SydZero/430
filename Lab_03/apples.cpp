#include <bits/stdc++.h>
using namespace std;

int main(){
    long long row, col;
    cin >> row >> col;

    char tree[row][col];
    int nums[col];

    string line;
    getline(cin, line);
    for(int r = 0; r < row; r++){
        getline(cin, line);
        for(int c = 0; c < col; c++){
            if(r == 0){
                nums[c] = 0;
            }
            if(line.at(c) == 'a'){
                nums[c]++;
                tree[r][c] = '.';
            } else if(line.at(c) == '#'){
                long long nr = r - 1; 
                tree[r][c] = line.at(c);
                while(nums[c] != 0){
                    tree[nr][c] = 'a';
                    nums[c]--;
                    nr--;
                }
            } else {
                tree[r][c] = line.at(c);
            }
            
        }
    }


    // for(int c = 0; c < col; c++){
    //     cout << nums[c] << " ";
    // }
    // cout << endl;

    long long nr = row - 1;
    for(int c = 0; c < col; c++){
        while(nums[c] != 0){
            tree[nr][c] = 'a';
            nums[c]--;
            nr--;
        }
        nr = row - 1;
    }

    for(int r = 0; r < row; r++){
        
        for(int c = 0; c < col; c++){
            cout << tree[r][c];
        }
        cout << endl;
    }

    

    return 0;
}
