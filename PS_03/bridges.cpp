#include <bits/stdc++.h>
using namespace std;

struct node{
    string name;
    int reachable;
    node* parent;

    node(string n): name(n){
        reachable = 1;
        parent = this;
    }
};


node* parent(node* curr){
    //cout << "    " << curr << " " << curr->parent << endl;
    if(curr->parent == curr){
        return curr;
    }
    curr->parent = parent(curr->parent);
    return curr->parent;
    
}

int main(){
    long long n;
    cin >> n;

    map<string, node*> buildings;
    
    for(long long i = 0; i < n; i++){
        string b1, b2;
        cin >> b1 >> b2;
        
        if(buildings.find(b1) == buildings.end()){
            buildings[b1] = new node(b1);
        }

        if(buildings.find(b2) == buildings.end()){
            buildings[b2] = new node(b2);
        }
        //cout << "FLAG 1" << endl;
        node* r1 = parent(buildings[b1]);
        node* r2 = parent(buildings[b2]);
        //cout << "FLAG 2" << endl;
        if(r1 == r2){
            //cout << "FLAG 3" << endl;
            cout << r2->reachable << endl;
        } else {
            //cout << "FLAG 4" << endl;
            long long tot = r1->reachable + r2->reachable;
            r1->parent = r2;
            r2->reachable = tot;
            r1->reachable = tot;

            cout << tot << endl;
        }
        //cout << "FLAG 5" << endl;
    }

    

    return 0;
}
