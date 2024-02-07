#include <bits/stdc++.h>
using namespace std;

int main(){
    long long a, b;
    long long sa, sb;

    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    while(true){
        cin >> a >> b;
        map<long long, long long> m;
        if(a == 0 && b == 0){
            break;
        }
        sa = 0;
        sb = 0;
        long long aog = a;
        long long bog = b;

        m[a] = sa;
        while(a > 1){         
            sa++;
            if(a % 2 == 0){
                a /= 2;
            } else {
                a = (3 * a) + 1;
            }
            m[a] = sa;
            
        }

        auto afound = m.begin();
        while(b >= 1){
            afound = m.find(b);
            if(afound != m.end()){
                break;
            }
            sb++;
            
            if(b % 2 == 0){
                b /= 2;
            } else {
                b = (3 * b) + 1;
            }
        }
        cout << aog << " needs " << afound->second << " steps, " << bog << " needs " << sb << " steps, they meet at " << b << endl;

    }


    return 0;
}
