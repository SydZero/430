#include <bits/stdc++.h>
using namespace std;

int main(){
    int nx, ny;

    int length = 100;
    int width = 75;

    double w;
    
    while (cin >> nx >> ny >> w){

        if(nx == ny && w == 0 && nx == 0){
            break;
        }

        vector<double> nxs;
        vector<double> nys;
        for(int i = 0; i < nx; i++){
            double temp;
            cin >> temp;
            nxs.push_back(temp);
        }
        for(int i = 0; i < ny; i++){
            double temp;
            cin >> temp;
            nys.push_back(temp);
        }

        sort(nxs.begin(), nxs.end(), less<double>());
        sort(nys.begin(), nys.end(), less<double>());

        double prev = 0;

        bool valid = true;
        for(int i = 0; valid && i < nx; i++){
            if(nxs.at(i) - (w / 2) <= prev){
                prev = nxs.at(i) + w / 2;
            } else {
                valid = false;
            }
        }

        if(prev < 75){
            valid = false;
        }

        prev = 0;
        for(int i = 0; valid && i < ny; i++){
            if(nys.at(i) - (w / 2) <= prev){
                prev = nys.at(i) + w / 2;
            } else {
                valid = false;
            }
        }
        if(prev < 100){
            valid = false;
        }

        if(valid){
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }


    }

    return 0;
}
