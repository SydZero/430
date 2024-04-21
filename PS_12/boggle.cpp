#include <bits/stdc++.h>
using namespace std;

struct node{
    map<int, node*> children;
    string end;

    node() : end("") {}
};

struct char_node{
    char c;
    set<char_node*> adj;
    bool visited;

    char_node(): c(0), visited(0){}
};

class trie {
public: 
    node* root;
    char_node* b[4][4];

    trie(){
        root = new node();
        for(int r = 0; r < 4; r++){
            for(int c = 0; c < 4; c++){
                b[r][c] = new char_node();
            }
        }

        for(int r = 0; r < 4; r++){
            for(int c = 0; c < 4; c++){
                for(int i = -1; i <= 1; i++){
                    for(int j = -1; j <= 1; j++){
                        if(i == 0 && j == 0){
                            continue;
                        } else if(r + i < 0 || r + i >= 4 || c + j < 0 || c + j >= 4){
                            continue;
                        } else {
                            b[r][c]->adj.insert(b[r + i][c + j]);
                        }
                    }
                }
            }
        }
    }

    void insert(string str){
        node* curr = root;
        for(char c : str){
            if(curr->children[c - 'A'] == nullptr){
                curr->children[c - 'A'] = new node();
            }
            curr = curr->children[c - 'A'];
        }
        curr->end = str;
    }

    void clear_visited(){
        for(int r = 0; r < 4; r++){
            for(int c = 0; c < 4; c++){
                b[r][c]->visited = false;
            }
        }
    }

    void fill_board(){
        for(int r = 0; r < 4; r++){
            for(int c = 0; c < 4; c++){
                cin >> b[r][c]->c;
                b[r][c]->visited = false;
            }
        }
    }

    string _dfs(char_node* n, node* curr){
        n->visited = true;
        if(curr->end != ""){
            return curr->end;
        }
        for(char_node* v : n->adj){
            if(!v->visited){
                return _dfs(v, curr);
            }
        }
        n->visited = false;
        return "";
    }

    void test_board(){
        string longest_word = "";
        int score = 0;
        int num_words = 0;
        set<string> words;

        for(int r = 0; r < 4; r++){
            for(int c = 0; c < 4; c++){
                node* curr = root;
                clear_visited();
                string w_found = _dfs(b[r][c], root);
                if(w_found != ""){
                    words.insert(w_found);    
                }
            }
        }
        for(string str : words){
            // cout << str << endl;
            switch(str.size()){
                case 3:
                case 4:
                    score += 1;
                    break;
                case 5:
                    score += 2;
                    break;
                case 6:
                    score += 3;
                    break;
                case 7:
                    score += 5;
                    break;
                case 8:
                    score += 11;
                    break;
            }
            num_words++;
            if(str.size() > longest_word.size()){
                longest_word = str;
            } else if(str.size() == longest_word.size() && str.compare(longest_word) < 0){
                longest_word = str;
            }
        }
            
        cout << score << " " << longest_word << " " << num_words << endl;
    }
};

int main(){
    int w;
    cin >> w;

    trie t = trie();

    for(int i = 0; i < w; i++){
        string temp;
        cin >> temp;
        t.insert(temp);
    }  

    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        t.fill_board();
        t.test_board();
    }

    return 0;
} 