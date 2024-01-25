#include <bits/stdc++.h>
using namespace std;

struct student{
    int class_num;
    vector<int> rankings;
};



int main(){
    string direction;
    vector<string> dirs;
    int minud = 0;
    int maxud = 0;
    int minlr = 0;
    int maxlr = 0;
    int ud = 0;
    int lr = 0;

    while(getline(cin, direction)){
        if(direction.empty()){
            break;
        }
        dirs.push_back(direction);
        if(direction == "up"){
            ud++;
        } else if(direction == "down"){
            ud--;
        } else if(direction == "left"){
            lr++;
        } else if(direction == "right"){
            lr--;
        }
        if(ud > maxud){
            maxud = ud;
        }
        if(ud < minud){
            minud = ud;
        }
        if(lr > maxlr){
            maxlr = lr;
        }
        if(lr < minlr){
            minlr = lr;
        }

    }

    if(maxud < 0){
        maxud = 0;
    }
    if(maxlr < 0){
        maxlr = 0;
    }


    int height = maxud + abs(minud) + 1;
    int width = maxlr + abs(minlr) + 1;

    char arr[height][width];

    
    for(int r = 0; r < height; r++){
        for(int c = 0; c < width; c++){
            arr[r][c] = ' ';
        }
    }

    int sud = maxud;
    int slr = maxlr;

    int r = sud;
    int c = slr;
    
    for(int i = 0; i < dirs.size(); i++){
        if(dirs.at(i) == "up"){
            r -= 1;
        } else if(dirs.at(i) == "down"){
            r += 1;
        } else if(dirs.at(i) == "left"){
            c -= 1;
        } else if(dirs.at(i) == "right"){
            c += 1;
        }
        arr[r][c] = '*';
       
    }
    arr[sud][slr] = 'S';
    arr[r][c] = 'E';

    string border ((width + 2), '#');

    cout << border << endl;

    for(int r1 = 0; r1 < height; r1++){
        cout << '#';
        for(int c1 = 0; c1 < width; c1++){
            cout << arr[r1][c1];
        }
        cout << '#' << endl;
    }

    cout << border << endl;
    return 0;
}