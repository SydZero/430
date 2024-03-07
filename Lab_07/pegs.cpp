#include <bits/stdc++.h>
using namespace std;

class board{
public:
    char b[5][9];
    int numpegs;

    board(): b(), numpegs(0){
        for (long long r = 0; r < 5; r++){
            for (long long c = 0; c < 9; c++){
                cin >> b[r][c];
                if(b[r][c] == 'o'){
                    numpegs++;
                }
            }
        } 
    }

    void find_min(int& moves, int& pegs){
        int minmoves = moves;
        int minpegs = pegs;
        //cout << "mins: " << minpegs << " " << minmoves << endl;
        for (long long r = 0; r < 5; r++){
            for (long long c = 0; c < 9; c++){
                if(b[r][c] != 'o'){
                    continue;
                }
                if(r > 1 && b[r - 1][c] == 'o' && b[r - 2][c] == '.'){
                    pair<int, int> ret = move({r, c}, 'u', moves, pegs);
                    if(ret.second < minpegs){
                        minpegs = ret.second;
                        minmoves = ret.first;
                    }
                }
                if(r < 5 && b[r + 1][c] == 'o' && b[r + 2][c] == '.'){
                    pair<int, int> ret = move({r, c}, 'd', moves, pegs);
                    if(ret.second < minpegs){
                        minpegs = ret.second;
                        minmoves = ret.first;
                    }
                }
                if(c > 1 && b[r][c - 1] == 'o' && b[r][c - 2] == '.'){
                    pair<int, int> ret = move({r, c}, 'l', moves, pegs);
                    if(ret.second < minpegs){
                        minpegs = ret.second;
                        minmoves = ret.first;
                    }
                }
                if(c < 7 && b[r][c + 1] == 'o' && b[r][c + 2] == '.'){
                    pair<int, int> ret = move({r, c}, 'r', moves, pegs);
                    if(ret.second < minpegs){
                        minpegs = ret.second;
                        minmoves = ret.first;
                    }
                }
            }
        }
        
        pegs = minpegs;
        moves = minmoves;
    }

    pair<int, int> move(pair<int, int> peg, char dir, int moves, int pegs){
        int ret = 0;
        moves++;
        pegs--;
        
        int rchange = 0;
        int lchange = 0;
        if(dir == 'u'){
            lchange = -1;
        } else if(dir == 'd'){
            lchange = 1;
        } else if(dir == 'l'){
            rchange = -1;
        } else if(dir == 'r'){
            rchange = 1;
        }
        b[peg.first][peg.second] = '.';
        b[peg.first + (lchange)][peg.second + (rchange)] = '.';
        b[peg.first + (2 * lchange)][peg.second + (2 * rchange)] = 'o';
        find_min(moves, pegs);
        b[peg.first][peg.second] = 'o';
        b[peg.first + (lchange)][peg.second + (rchange)] = 'o';
        b[peg.first + (2 * lchange)][peg.second + (2 * rchange)] = '.';

        return {moves, pegs};
    }

    void print_board(){
        for (long long r = 0; r < 5; r++){
            for (long long c = 0; c < 9; c++){
                cout << b[r][c];
            }
            cout << endl;
        }
        cout << endl;
    }


};


int main(){
    long long n;
    cin >> n;
    for(int i = 0; i < n; i++){
        board b = board();
        int moves = 0;
        int pegs = b.numpegs;
        b.find_min(moves, pegs);
        cout << pegs << " " << moves << endl;
    }    
    
    return 0;
}