#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


using std::cout, std::cin, std::endl;
using std::string;

int main(){

    int T = 0;
    cin >> T;

    std::vector<int> nums;
    int Ng, Nm;
    for(int i = 0; i < T; i++){
        cin >> Ng >> Nm;
        std::vector<int> godzilla;
        std::vector<int> mechaG;

        int temp;
        for(int j = 0; j < Ng; j++){
            cin >> temp;
            godzilla.push_back(temp);
        }
        for(int j = 0; j < Nm; j++){
            cin >> temp;
            mechaG.push_back(temp);
        }

        std::sort(godzilla.begin(), godzilla.end());
        std::sort(mechaG.begin(), mechaG.end());

        std::reverse(godzilla.begin(), godzilla.end());
        std::reverse(mechaG.begin(), mechaG.end());

        while(godzilla.size() != 0 && mechaG.size() != 0){
            if(godzilla.at(godzilla.size() - 1) < mechaG.at(mechaG.size() - 1)){
                godzilla.pop_back();
            } else if(godzilla.at(0) > mechaG.at(0)){
                mechaG.pop_back();
            } else {
                mechaG.pop_back();
            }
        }

        if(godzilla.size() != 0){
            cout << "Godzilla" << endl;
        } else if(mechaG.size() != 0){
            cout << "MechaGodzilla" << endl;
        } else {
            cout << "uncertain" << endl;
        }

    }

      


    return 0;
}