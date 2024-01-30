#include <bits/stdc++.h>
using namespace std;



int main(){
    int X;
    cin >> X;
    cout << X << ":" << endl;
    for(int i = 2; i < X; i++){
        if((X % (i + i - 1)) == 0 || (X % (i + i - 1)) == i ){
            cout << i << "," << i - 1 << endl;
        }
        if(X % i == 0){
            cout << i << "," << i << endl;
        }
    }
    
    return 0;
}
