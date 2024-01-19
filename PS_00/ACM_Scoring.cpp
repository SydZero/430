#include <iostream>
#include <string>
#include <unordered_map>

using std::cout, std::cin, std::endl;
using std::string;
using std::unordered_map;

struct prob_data {
    int mins;
    int num_wrong;
    bool solved;

};

int main(){
    unordered_map<char, prob_data> stats;
    int m = -1;
    char prob;
    string right_str;
    cin >> m;


    while(m != -1){
        cin >> prob >> right_str;
        if(stats.find(prob) == stats.end()){
            prob_data temp;
            temp.mins = 0;
            temp.num_wrong = 0;
            temp.solved = false;
            stats[prob] = temp;
        }

        if(right_str == "right"){
            stats[prob].mins = m;
            stats[prob].solved = true;
        }

        if(right_str == "wrong"){
            stats[prob].num_wrong += 1;
            
        }
        cin >> m;
    }

    int total_solved = 0;
    int time = 0;

    for(std::pair<char, prob_data> problem: stats){
        if(problem.second.solved){
            total_solved += 1;
            time += (problem.second.mins + (problem.second.num_wrong * 20));
        }
    }
    cout << total_solved << " " << time << endl;

    return 0;
}