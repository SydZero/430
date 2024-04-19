#include <bits/stdc++.h>
using namespace std;

struct node{
    node* children[26];
    int num;

    node():num(0){
        for(int i = 0; i < 26; i++){
            children[i] = nullptr;
        }
    }
};

class trie {
public: 
    node* root;

    trie(){
        root = new node();
    }

    int insert(string str){
        node* curr = root;
        for(char c : str){
            if(curr->children[c - 'a'] == nullptr){
                curr->children[c - 'a'] = new node();
            }
            curr = curr->children[c - 'a'];
            curr->num++;
        }
        return curr->num - 1;
    }
};

int main(){
    int n;

    cin >> n;

    trie t = trie();

    for(int i = 0; i < n; i++){
        string temp;
        cin >> temp;

        cout << t.insert(temp) << endl;

    }    
    return 0;
} 