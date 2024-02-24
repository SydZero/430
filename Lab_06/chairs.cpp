#include <bits/stdc++.h>
using namespace std;

struct node{
    node* next;
    node* prev;
    long long i;
    long long fav;

    node(node* n, node* p, long long f, long long ind){
        
        next = n;
        prev = p;
        fav = f;
        i = ind;
    }
};

int main(){
    long long t;
    cin >> t;

    node* in[t];
    for(long long i = 0; i < t; i++){
        long long temp;
        long long next = i + 1;

        if(next == t){
            next = 0;
        }
        cin >> temp;

        in[i] = new node(nullptr, nullptr, temp, i + 1);
    }
    for(long long i = 0; i < t; i++){
        
        long long prev = i - 1;
        if(i == 0){
            prev = t - 1;
        }
        long long next = i + 1;

        if(next == t){
            next = 0;
        }
        in[i]->next = in[next];
        in[i]->prev = in[prev];
    }

    node* curr = in[0];
    for(long long i = 0; i < t - 1; i++){
        //cout << "moving " <<  i << endl;
        long long move = (curr->fav) + 1 % (t - i);   
          
        for(int j = 0; j < move; j++){
            //cout << " call " << curr->i << endl;  
            curr = curr->next;
        }
        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;
        curr = curr->next;
    }

    cout << curr->i << endl;
      
    return 0;
}
