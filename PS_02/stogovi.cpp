#include <bits/stdc++.h>
using namespace std;

// ideas
// node with i and v vals, pointer to prev stack top node
// vector of pointers to nodes
// set to determine different numbers in two stacks
// singly linked list but make it gross

struct node{
    int top;
    node* under;
};

bool DEBUG = false;

void print_stacks(vector<node*> stacks){
    if(!DEBUG){
        return;
    }
    for(int i = 0; i < stacks.size(); i++){
        cout << "stack " << i << ": ";
        node* curr = stacks.at(i);
        while(curr){
            cout << curr->top << " ";
            curr = curr->under;
        }
        cout << endl;
    }
    cout << "------------" << endl;
}

void print_set(set<int> vals){
    if(vals.empty()){
        return;
    }
    for(int str: vals){
        cout << str << " " ;
    }
    cout << endl;
}

int main(){

    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    //some data structure, not vec of stacks
    vector<node*> nums;
    nums.push_back(nullptr);

    char ins;

    for(int i = 0; i < n; i++){
        cin >> ins;
        int v;
        cin >> v;
        node* temp_node = new node();
        if(ins == 'a'){
            temp_node->under = nums.at(v);
            temp_node->top = i + 1;
            nums.push_back(temp_node);
        } else if(ins == 'b'){
            cout << nums.at(v)->top << endl;
            nums.push_back(nums.at(v)->under);
        } else if(ins == 'c'){
            set<int> unique;
            int w;
            cin >> w;
            
            node* curr = nums.at(v);
            while(curr){
                unique.insert(curr->top);
                curr = curr->under;
            }
            
            curr = nums.at(w);
            int count = 0;
            while(curr){
                if(unique.find(curr->top) != unique.end()){
                    count++;
                }
                curr = curr->under;
            }
            cout << count << endl;
            temp_node = nums.at(v);
            nums.push_back(temp_node);
        }
        print_stacks(nums);

    }


    return 0;
}