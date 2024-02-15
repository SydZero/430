#include <bits/stdc++.h>
using namespace std;

struct node{
    node* parent;
    long long sum;
    long long lower_bound;
    long long upper_bound;

    node(){
        parent = this;
        sum = 0;
        lower_bound = 0;
        upper_bound = 0;
    }
};


long long find_index(long long n){
    return n & (n + 1);
}

class fenwick{

    public: 
        long long n;
        node* tree;


        fenwick(long long n){
            tree = new node[find_index(n) + 1];
            for(long long i = 0; i < n; i++){
                tree[i] = node();
            }
        }
    


};

int main(){
    long long n, k;
    
    cin >> n >> k;
    bool bits[n];

    for(long long i = 0; i < n; i++){
        bits[i] = false;
    }

    for(long long i = 0; i < k; i++){
        char ins;
        cin >> ins;
        if(ins == 'F'){
            long long i;
            cin >> i;
            bits[i] = !bits[i];

        } else if(ins == 'C'){
            long long l, r, count;
            count = 0;
            cin >> l >> r;
            for(int j = l; j <= r; j++){
                if(bits[j] == true){
                    count++;
                }
            }
            cout << count << endl;
        }
    }
    
    return 0;
}
