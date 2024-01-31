#include <bits/stdc++.h>
using namespace std;

struct node{
    string str;
    node* next;
    node* last;
};


int main(){

    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    int n;

    cin >> n;
    vector<node*> nodes;
    string temp;
    for(int i = 0; i < n; i++){
        cin >>  temp;
        node* tnode = new node{temp, nullptr, nullptr};
        nodes.push_back(tnode);
    }

    int a, b;
    int end = 0;
    while(cin >> a >> b){
        a -= 1;
        b -= 1;
        if(nodes[b]->next == nullptr){
            nodes[b]->last = nodes[b];
        }
        if(nodes[a]->next == nullptr){
            nodes[a]->next = nodes[b];
            nodes[a]->last = nodes[b]->last;
        } else {
            nodes[a]->last->next = nodes[b];
            nodes[a]->last = nodes[b]->last;
        }

        end = a;
    }
    
    node* curr = nodes[a];
    while(curr != nullptr){
        cout << curr->str;
        curr = curr->next;
    }
    cout << endl;

    return 0;
}