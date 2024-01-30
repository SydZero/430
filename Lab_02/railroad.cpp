#include <bits/stdc++.h>
using namespace std;



int main(){
    int X, Y;
    cin >> X >> Y;

    int insx = X * 2;
    int outsx = X * 2;
    int insy = Y;
    int outsy = 2 * Y;


    if(Y % 2 == 0){
        cout << "possible" << endl;
    } else {
        cout << "impossible" << endl;
    }

    return 0;
}
