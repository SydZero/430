#include <bits/stdc++.h>
using namespace std;

struct node{
    string name;
    set<node*> adj;
    double time;
    set<club*> clubs;

    node(int name): name(name){}
};

struct party{
    string name;
    
    party(string name): name(name){}
};

struct club{
    string name;
    int b;
    int p;
    int t;

    club(int a, int b, int p, int t): a(a), b(b), p(p), t(t){}
};

class mycomp{
public:
    bool operator() (const node* p1, const node* p2) const{
        return p1->time > p2->time;
    }
};

class graph{
public:
    int n;
    int i, g, s, m;
    vector<int> facilities;
    vector<road*> roads;
    vector<node*> nodes;

    graph(int n, int i, int g, int s, int m): n(n), i(i), g(g), s(s), m(m){
        for(int i = 0; i < n; i++){
            nodes.push_back(new node(i));
        }
    }

    void add_road(int a, int b, int p, int t){
        roads.push_back(new road(a, b, p, t));
    }
};

int main(){
    int t;
    cin >> t;

    for(int k = 0; k < t; k++){
        int n;
        cin >> n;

    }

    return 0;
} 