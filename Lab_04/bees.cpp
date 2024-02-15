#include <bits/stdc++.h>
using namespace std;

bool isVowel(char c){
    if(c == 'a' || c == 'e' || c == 'i' ||c == 'o' ||c == 'u'||c == 'y'){
        return true;
    }
    return false;
}

int main(){
    long long n;
    

    while(cin >> n){
        if (n == 0){
            break;
        }
        long long max = 0;
        string curr_str = "";
        for(int i = 0; i < n; i++){
            string str;
            cin >> str;
            int count = 0;
            for(int i = 0; i < str.size() - 1; i++){
                if(isVowel(str.at(i)) && str.at(i) == str.at(i + 1)){
                    count++;
                }
            }
            if(count >= max){
                max = count;
                curr_str = str;
            }        
        }
        cout << curr_str << endl;
    
    }

    

    return 0;
}
