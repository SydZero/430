#include <bits/stdc++.h>
using namespace std;

struct node{
    int max;
    int min;

    node(int min, int max): min(min), max(max){
        min = INT32_MAX;
        max = INT32_MIN;
    }
};


class segment_tree{
public:
    long long n;
    vector<node*> arr;
    map<int, int> indexes;

    segment_tree(vector<pair<int, int>>& starter) {
        for(int i = 0; i < n; i++){
            arr.push_back(new node(starter.at(i).first, starter.at(i).second));
        }
    }

    int find_max(int y1, int y2, int i = 1) {
        //cout << "find max of " << y1 << " " << y2 << endl;
        if (y1 > y2 || arr.at(i)->yearmin > y2 || arr.at(i)->yearmax < y1) {
            return INT_MIN;
        }
        if (arr.at(i)->yearmin >= y1 && arr.at(i)->yearmax <= y2) {
            return arr.at(i)->max; 
        }
        
        return max(find_max(y1, min(y2, arr.at(i * 2)->yearmax), i * 2), find_max(max(y1, arr.at((i * 2) + 1)->yearmin), y2, (i * 2) + 1));
    }

    int query(int year1, int year2){
        auto y1ind = indexes.find(year1);
        if(y1ind == indexes.end() || y1ind->second + (year2 - year1) >= arr.size() || arr.at(y1ind->second + (year2 - year1))->yearmax != year2){
            return 0;
        }  
        auto y2ind = indexes.find(year2);
        if(arr.at(y1ind->second) > arr.at(y2ind->second)){
            return -1;
        }
        int max = find_max(year1 + 1, year2 - 1);
        //cout << max << " < " << arr.at(y2ind->second)->max << endl;
        if(max >= arr.at(y2ind->second)->max){
            return -1;
        }
        return 1;
        
    }

    void print(){
        for(int i = 1; i < arr.size(); i++){
            print_node(arr.at(i));
        }
        cout << endl;
    }
};

int main(){
    long long n, m;
    
    while(true){
        scanf("%lld" , &n);
        vector<pair<int, int>> years;
    
        for(long long i = 0; i < n; i++){
            int first, second;
            scanf("%i" , &first);
            scanf("%i" , &second);
            years.push_back({first, second});
        }

        segment_tree st(years);
        //st.print();
        
        scanf("%lld", &m);
        if(n == 0){
            break;
        }

        for(long long i = 0; i < m; i++){
            int y1, y2;
            scanf("%i" , &y1);
            scanf("%i" , &y2);
            int res = st.query(y1, y2);
            if(res == 1){
                cout << "true" << endl;
            } else if(res == 0){
                cout << "maybe" << endl;
            } else {
                cout << "false" << endl;
            }
        }
        cout << endl;
        
    }
    
    
    return 0;
}



int main(){
    int n, h;      
    cin >> n >> h;

    map<int, set<int>> obs;
    
    for(int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        int start = 0;
        int mult = 1;
        if(i % 2 == 0){
            obs[0].insert(temp);
        } else {
            obs[h - 1].insert(h - 1);
        }
    }


    return 0;
}
