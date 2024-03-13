#include <bits/stdc++.h>
using namespace std;

long long fewer_than(long long m, long long n, vector<long long>& train){
    //cout << "fewer than " << m << ":  " << endl;
    long long lot = m - 1;
    long long num_locamotives = 0;
    long long begin = 0;
    long long i = 0;
    while(i < train.size() && begin < n){
        num_locamotives++;
        //cout << "  " << "locamotive at: " << begin << endl;
        if(begin + lot < train.at(i)){
            begin = train.at(i);
            // i++;
        } else {
            while(i < train.size() && begin + lot >= train.at(i)){
                i++;
            }
            begin += lot + 1;
        }
        
    }
    //cout << begin << endl;
    if(begin < n){
        //cout << "1  " << "locamotive at: " << begin << endl;
        num_locamotives++;
    }
    //cout << num_locamotives << " locamotives" << endl;
    return num_locamotives;
}

int main(){
    long long t;
    cin >> t;
    
    for(long long i = 0; i < t; i++){  
        long long n, w, l;
        cin >> n >> w >> l;
        vector<long long> train;
        for(int j = 0; j < w; j++){
            int has;
            cin >> has;
            train.push_back(has - 1);
        }
        long long left = 1;
        long long right = n;
        long long m = (left + right) / 2;
        long long numreq = -1; 
        //cout << l << " locamotives" << endl;
        while(left < right) {
            //cout << left << " < " << right << endl;
            m = ((left + right) / 2);
            //m = 1;
            long long numreq = fewer_than(m, n, train);
            //cout << numreq;
            if(numreq <= l) {
                //cout << " <= " << l <<  " good" << endl;
                right = m;
            } else {
                //cout << " > " << l <<  " bad" << endl;
                left = m + 1;
            }
            //break;
        }
        //cout << left << " >= " << right << endl;
        cout << left << endl;
    }
      
    return 0;
}
