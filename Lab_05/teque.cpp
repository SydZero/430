#include <bits/stdc++.h>
using namespace std;

class Teque{
public:
    deque<long long> front;
    deque<long long> back;

    Teque():front(0), back(0){}

    void push_front(long long i){
        front.push_front(i);
        balance();
    }

    void push_back(long long i){
        back.push_back(i);
        balance();
    }

    void push_middle(long long i){
        front.push_back(i);
        balance();
    }

    void get(long long i){
        if(i < front.size()){
            cout << front.at(i) << endl;
        } else {
            cout << back.at(i - front.size()) << endl;
        }
    }

    void balance(){
        if(front.size() > back.size() + 1){
            back.push_front(front.back());
            front.pop_back();
        } else if(back.size() > front.size()){
            front.push_back(back.front());
            back.pop_front();
        }
    }

    void print(){
        for(int i = 0; i < front.size(); i++){
            cout << front.at(i) << " ";
        }
        cout << " | ";
        for(int i = 0; i < back.size(); i++){
            cout << back.at(i) << " ";
        }
        cout << endl;
    }
};

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Teque t = Teque();
    long long n;
    cin >> n;
    string ins;
    long long num;
    for(int i = 0; i < n; i++){
        cin >> ins >> num;
        if(ins == "push_back"){
            t.push_back(num);
        } else if(ins == "push_front"){
            t.push_front(num);
        } else if(ins == "push_middle"){
            t.push_middle(num);
        }else if(ins == "get"){
            t.get(num);
        }
        //t.print();
        
    }
            
    return 0;
}
