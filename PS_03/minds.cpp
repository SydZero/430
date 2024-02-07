#include <bits/stdc++.h>
using namespace std;

struct node{
    node* parent;
    long long size;
    long long numfound;
    long long value;

    node(int t): parent(this), size(1), numfound(1), value(t){
    }
};

node* parent(node* p){
    if(p != p->parent){
        node* prent = parent(p->parent);
        p->parent = prent;
        return prent;
    }
    return p;
}

int main(){
    int n;
    cin >> n;

    long long m;
    
    map<long long, node*> ingredients;
    long long num = 0;

    for(long long i = 0; i < n; i++){
        set<node*> rts;
        cin >> m;
        long long c;
        bool make = true;
        for(long long j = 0; j < m; j++){
            cin >> c;
            if(ingredients[c]){
                node* rt = parent(ingredients[c]);
                rts.insert(rt);
                rt->numfound++;
            } else {
                ingredients[c] = new node(c);
                rts.insert(ingredients[c]);
            }
        }
        bool valid = true;
        for(node* root : rts){
            if(root->numfound < root->size){
                valid = false;
                break;
            }
        }
        if(valid){
            //cout << "valid" << endl;
            node* nr = *rts.begin();
            long long new_size = 0;
            for(node* root : rts){
                root->parent = nr;
                new_size += root->size;
            }
            num++;
            nr->size = new_size;
            nr->numfound = 0;
        } else {
            //cout << "not valid" << endl;
            for(node* root : rts){
                root->numfound = 0;
            }
        }
    }
    cout << num << endl;

    return 0;
}
