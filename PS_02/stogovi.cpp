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

void print_stacks(vector<node> stacks){
    for(int i = 0; i < stacks.size(); i++){
        cout << "stack " << i + 1 << ": " << stacks.at(i).under << " ";
        node* curr = stacks.at(i).under;
        while(curr){
            cout << curr->top << " ";
            curr = curr->under;
        }
        cout << endl;
    }
    cout << "------------" << endl;
}

int main(){

    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    //some data structure, not vec of stacks
    vector<node> nums;

    char ins;

    for(int i = 0; i < n; i++){
        cin >> ins;
        int v;
        cin >> v;
        v--;
        node temp_node;
        if(ins == 'a'){
            if(v == -1){
                temp_node.under = nullptr;
                
            } else {
                temp_node.under = &nums.at(v);
            }
            temp_node.top = i + 1;
            nums.push_back(temp_node);
        } else if(ins == 'b'){
            cout << nums.at(v).top << endl;
            nums.push_back(*nums.at(v).under);
        } else if(ins == 'c'){
            set<int> unique;
            int w;
            cin >> w;
            w--;
            unique.insert(nums.at(v).top);
            unique.insert(nums.at(w).top);
            node* curr = nums.at(v).under;
            while(curr){
                unique.insert(curr->top);
                curr = curr->under;
            }
            unique.insert(nums.at(w).top);
            curr = nums.at(w).under;
            while(curr){
                unique.insert(curr->top);
                curr = curr->under;
            }
            cout << unique.size() << endl;
            temp_node.under = &nums.at(v);
            temp_node.top = i + 1;
            nums.push_back(temp_node);
        }
        print_stacks(nums);

    }


    return 0;
}