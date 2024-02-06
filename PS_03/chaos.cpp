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

int main(){
    int n;
    cin >> n;

    int p[n];
    int order[n];
    node* train[n];
    vector<node*> segments;

    long long chaos = 0;

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

    segments.push_back(train[0]);

    int curr;
    chaos = _round(train[0]->total);

    for(int i = 0; i < n; i++){
        cin >> curr;
        curr--;
        
        if(train[curr]->next){
            segments.push_back(train[curr]->next);
            train[curr]->next->prev = nullptr;
        }
        if(train[curr]->prev){
            train[curr]->prev->next = nullptr;
        }
        dec(train[curr], train[curr]->total);

        train[curr]->del = true;

        long long temp_tot = 0;

        for(long long j = 0; j < segments.size(); j++){
            if(segments.at(j)->del == true){
                swap(segments.at(j), segments.at(segments.size() - 1));
                segments.pop_back();
                j--;
                continue;
            }
              
            temp_tot += _round(segments.at(j)->total);
        }

        chaos = max(chaos, temp_tot * (long long)(segments.size()));
    } 
    cout << chaos << endl;
    

    return 0;
}
