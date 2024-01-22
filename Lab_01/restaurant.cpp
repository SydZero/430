#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


using std::cout, std::cin, std::endl;
using std::string;

int main(){
    int N = 0;
    cin >> N;

    while(N != 0){
        string instruction;
        int m;
        int p1 = 0;
        int p2 = 0;
        for(int i = 0; i < N; i++){
            cin >> instruction;
            cin >> m;

            if(instruction == "DROP"){
                p2 += m;
                cout << "DROP 2 " << m << endl;
            } else if (instruction == "TAKE"){
                if(p1 < m){
                    int move = m - p1;

                    if(p1 != 0){
                        cout << "TAKE 1 " << p1 << endl;
                        p1 = 0;
                    }
                    cout << "MOVE 2->1 " << p2 << endl;
                    cout << "TAKE 1 " << move << endl;
                    p1 = p2 - move;
                    p2 = 0;
                } else {
                    cout << "TAKE 1 " << m << endl;
                    p1 -= m;
                }
                

            }

        }
        cout << endl;
        cin >> N;
    }


    return 0;
}