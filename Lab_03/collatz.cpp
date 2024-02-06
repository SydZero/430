#include <bits/stdc++.h>
using namespace std;

int main(){
    int a, b;
    int sa, sb;

    while(true){
        cin >> a >> b;
        map<long long, long long> m;
        if(a == 0 && b == 0){
            break;
        }
        sa = 0;
        sb = 0;
        int aog = a;
        int bog = b;

        m.insert({a, sa});
        while(a > 1){         
            sa++;
            if(a % 2 == 0){
                a /= 2;
            } else {
                a = (3 * a) + 1;
            }
            m.insert({a, sa});
            
        }
        m.insert({a, sa});
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
