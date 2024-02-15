#include <bits/stdc++.h>
using namespace std;

class gem_collection{
    public:
        gem_collection(){
            
        }
};



int main(){
    long long n, q;
    long long v[6];
    
    cin >> n >> q;
    cin >> v[0] >> v[1] >> v[2] >> v[3] >> v[4] >> v[5];

    long long p[n];
    string str;
    cin >> str;

    for(long long i = 0; i < n; i++){
        p[i] = (str.at(i)) - '0';
    }
    
    for(long long i = 0; i < q; i++){
        int ins;
        cin >> ins;
        if(ins == 1){
            long long k, pi;
            cin >> k >> pi;
            p[k] = p[pi];
            
        } else if(ins == 2){
            long long pi, v;
            cin >> v >> pi;
            
        } else if(ins == 3){
            long long li, ri;
            cin >> li >> ri;
            
        }

    }

    

    return 0;
}
