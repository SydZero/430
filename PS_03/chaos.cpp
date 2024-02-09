#include <bits/stdc++.h>
using namespace std;

struct node{
    node* next;
    node* prev;
    int value;
    int total;
    bool del;

    node(int t): next(nullptr), prev(nullptr), value(t), total(0), del(false){
    }
};

int count(node* n){
    if(!n){
        return 0;
    }
    node* curr = n;
    int total = 0;
    while(curr){
        total += curr->value;
        curr = curr->next;
    }

    if(total % 10 == 0){
        return total;
    }
    return total + 10 - (total % 10);

}

void print_node(node* curr){
    cout << curr->total << " {";
    while(curr){
        cout << curr->value << "<-";
        curr = curr->next;
    }
    cout << "}" << endl;
}

long long _round(long long total){
    if(total % 10 == 0){
        return total;
    }
    return total + 10 - (total % 10);

}

void dec(node* curr, long long n){
    curr->total -= n;
    if(curr->prev){
        dec(curr->prev, n);
    }
}

class train{
    public:
        map<long long, node*> trains;
        node** car;
        long long order[];

        train(){

        }
};


int main(){
    int n;
    cin >> n;

    int p[n];
    int order[n];
    node* train[n];
    vector<node*> segments;

    long long curr_chaos = 0;
    long long unround_chaos = 0;
    long long max_chaos = 0;

    for(int i = 0; i < n; i++){
        cin >> p[i];
        train[i] = new node(p[i]);
    }

    long long total = 0;
    for(int i = n-1; i >= 0; i--){
        if(i != 0){
            train[i]->prev = train[i - 1];
            train[i - 1]->next = train[i];
        }
        total += train[i]->value;
        train[i]->total = total;
    }

    long long curr;
    long long segs = 1;
    unround_chaos = train[0]->total;
    curr_chaos = _round(train[0]->total);
    max_chaos = curr_chaos;

    for(long long i = 0; i < n; i++){
        cin >> curr;
        curr--;
        
        if(train[curr]->next){
            segs++;
            train[curr]->next->prev = nullptr;
        }
        if(train[curr]->prev){
            train[curr]->prev->next = nullptr;
        } else {
            segs--;
        }

        curr_chaos = _round(unround_chaos - train[curr]->total) + _round(train[curr]->total - train[curr]->value);

        unround_chaos -= train[curr]->value;



        dec(train[curr], train[curr]->total);
        

        max_chaos = max(max_chaos, curr_chaos * segs);
    } 
    cout << max_chaos << endl;
    

    return 0;
}
