#include <bits/stdc++.h>
using namespace std;

// ideas
// node with i and v vals, pointer to prev stack top node
// vector of pointers to nodes
// set to determine different numbers in two stacks
// singly linked list but make it gross

struct node{
    long long top;
    node* under;
    long long num_below;
};

bool DEBUG = true;

void print_stacks(node* stacks[], long long n){
    for(long long i = 0; i <= n + 1; i++){
        cout << "stack " << i << ": ";
        node* curr = stacks[i];
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

    long long n;
    cin >> n;

    //some data structure, not vec of stacks
    node* nums[n+1];
    nums[0] = nullptr;

    char ins;

    for(long long i = 1; i <= n; i++){
        cin >> ins;
        long long v;
        cin >> v;
        node* temp_node = new node();
        if(ins == 'a'){
            temp_node->under = nums[v];
            temp_node->top = i;
            if(nums[v] == nullptr){
                temp_node->num_below = 1;
            } else {
                temp_node->num_below = temp_node->under->num_below + 1;
            }
            nums[i] = temp_node;
        } else if(ins == 'b'){
            cout << nums[v]->top << endl;
            nums[i] = nums[v]->under;
        } else if(ins == 'c'){
            set<int> unique;
            long long w;
            cin >> w;
            
            node* currv = nums[v];
            node* currw = nums[w];

            //look through each until ptrs same or nullptr
            while(currv != nullptr && currw != nullptr){
                //cout << "compare: " <<  currv->top << " " << currw->top << endl;
                if(currv == currw){
                    cout << currv->num_below << endl;
                    break;
                } else if(currv->top > currw->top){
                    currv = currv->under;
                } else {
                    currw = currw->under;
                }
            }
            temp_node = nums[v];
            nums[i] = temp_node;
        }

        // if(DEBUG){
        //     print_stacks(nums, i - 1);
        // }

    }


    return 0;
}