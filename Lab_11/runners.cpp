#include <bits/stdc++.h>
using namespace std;

struct runner{
    string name;
    double first;
    double other;
    
    runner(string name, double first, double other): name(name), first(first), other(other){}
};

class mycompother{
public:
    bool operator() (const runner* p1, const runner* p2) const{
        return p1->other < p2->other;
    }
};

class mycompfirst{
public:
    bool operator() (const runner* p1, const runner* p2) const{
        return p1->first < p2->first;
    }
};

int main(){
    int n;

    cin >> n;

    vector<runner*> otherl;
    vector<runner*> firstl;

    for(int i = 0; i < n; i++){
        string name;
        double first, other;
        cin >> name >> first >> other;
        runner* r = new runner(name, first, other);
        otherl.push_back(r);
        firstl.push_back(r);
    }

    sort(otherl.begin(), otherl.end(), mycompother());
    sort(firstl.begin(), firstl.end(), mycompfirst());

    // if(firstl.front() != otherl.at(0) && firstl.front() != otherl.at(1) && firstl.front() != otherl.at(2)){
    //     double sum = firstl.at(0)->first + otherl.at(0)->other + otherl.at(1)->other + otherl.at(2)->other;
    //     cout << sum << endl << firstl.at(0)->name << endl << otherl.at(0)->name << endl << otherl.at(1)->name << endl << otherl.at(2)->name << endl;
    // // }

    // for(runner* r : otherl){
    //     cout << r->name << " ";
    // }
    // cout << endl;

    // for(runner* r : firstl){
    //     cout << r->name << " ";
    // }
    
    double sum = 0;

    set<runner*> otherset;
    
    for(int i = 0; i < 4; i++){
        sum+= otherl.at(i)->other;
        otherset.insert(otherl.at(i));
    }

    double min = DBL_MAX;
    runner* first;

    string final_str = "";

    for(int i = 0; i < 4; i++){
        if(otherset.find(firstl.at(i)) == otherset.end()){
            if(min > sum - otherl.at(3)->other + firstl.at(i)->first){
                min = sum - otherl.at(3)->other + firstl.at(i)->first;
                final_str = firstl.at(i)->name + "\n" + otherl.at(0)->name + "\n" + otherl.at(1)->name + "\n" + otherl.at(2)->name + "\n";
            }
        } else {
            if(min > sum - firstl.at(i)->other + firstl.at(i)->first){
                min = sum - firstl.at(i)->other + firstl.at(i)->first;
                final_str = firstl.at(i)->name + "\n";
                for(int j = 0; j < 4; j++){
                    if(otherl.at(j) == firstl.at(i)){
                        continue;
                    } else {
                        final_str += otherl.at(j)->name + "\n";
                    }
                }
                
            }
        }
    }

    cout << min << endl;
    cout << final_str;



    
    return 0;
} 