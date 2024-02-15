#include <bits/stdc++.h>
using namespace std;

struct node{
    node* parent;
    long long value;
    long long total;
    bool intree;


    node(long long t): parent(this), value(t), total(t), intree(false){
    }
};

long long _round(long long total){
    if(total % 10 == 0){
        return total;
    }
    return total + 10 - (total % 10);

}

node* parent(node* p){
    if(p->parent != p){
        return parent(p->parent);
    }
    return p;
}

class Train{
    public:
        long long n;
        vector<node*> car;
        vector<long long> order;
        vector<long long> all_chaos;
        vector<long long> current_roots;
        long long max_chaos;

        Train(long long n): n(n){
            car = vector<node*>();
            order = vector<long long>();
            all_chaos = vector<long long>();
            max_chaos = 0;
        }

        long long find_max(){
            long long curr_chaos = 0;
            long long segments = 0;

            for(int i = n-1; i >= 0; i--){
                //cout << i << ": " << order[i] << endl;
                long long ind = order[i];
                node* curr = car[ind];
                node* prev = nullptr;
                node* next = nullptr;
                curr->intree = true;

                long long change = 0;


                if(ind < n - 1){
                    
                    next = car[ind + 1];
                    if(next->intree){
                        next->parent = curr->parent;
                        change -= _round(next->total);                 
                        next->parent = curr->parent;
                        curr->parent->total += next->total;
                    }
                }

                if(ind > 0){
                    prev = car[ind - 1];
                    if(prev->intree){
                        curr->parent = parent(prev);
                        if(curr->parent != curr){
                            change -= _round(curr->parent->total);
                            curr->parent->total += curr->total;
                        }
                        
                    }
                }
            
                change += _round(parent(curr)->total);
                curr_chaos += change;
                if((!prev || !(prev->intree)) && (!next || !(next->intree))){
                    segments++;
                } else if((prev && prev->intree) && (next && next->intree)){
                    segments--;
                }

                max_chaos = max(max_chaos, curr_chaos * segments);
                //cout << "curr chaos: " << curr_chaos << " * " << segments << endl;
            }
            return max_chaos;
        }

};


int main(){
    long long n;
    cin >> n;

    Train train = Train(n);
    long long p[n];

    for(int i = 0; i < n; i++){
        cin >> p[i];
        train.car.push_back(new node(p[i]));
    }

    for(long long i = 0; i < n; i++){
        long long curr;
        cin >> curr;
        curr--;
        train.order.push_back(curr);
    }

    train.find_max();

    cout << train.max_chaos << endl;
    

    return 0;
}
