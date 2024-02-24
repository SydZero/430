#include <bits/stdc++.h>
using namespace std;

struct node{
    int yearmin;
    int yearmax;
    int max;
    int min;
    bool cont;
    bool empty;

    node(){
        yearmin = INT32_MAX;
        yearmax = INT32_MIN;
        min = INT32_MAX;
        max = INT32_MIN;
        cont = true;
        empty = true;
    }
};

void print_node(node* n){
    cout << "year:" << n->yearmin << "-" << n->yearmax << " min:" << n->min << " max:" << n->max << " cont:" << n->cont << " empty:" << n->empty << endl;;
}

class segment_tree{
public:
    long long n;
    vector<node*> arr;
    map<int, int> indexes;

    segment_tree(vector<pair<int, int>>& starter) {
        int sqrtn = sqrt(starter.size()) + 1;
        int halfn = pow(sqrtn, 2);
        n = 2 * halfn;

        for(int i = 0; i < n; i++){
            arr.push_back(new node());
        }
        
        for(int i = 0; i < starter.size(); i++){
            indexes.insert({starter.at(i).first, i + halfn});
            arr.at(i + halfn)->yearmin = starter.at(i).first;
            arr.at(i + halfn)->yearmax = starter.at(i).first;
            arr.at(i + halfn)->max = starter.at(i).second;
            arr.at(i + halfn)->min = starter.at(i).second;
            arr.at(i + halfn)->cont = true;  
            arr.at(i + halfn)->empty = false;

        }
        
        for(int i = halfn - 1; i > 0; i--){
            arr.at(i)->yearmax = max(arr.at(i * 2)->yearmax, arr.at((i * 2) + 1)->yearmax);
            arr.at(i)->yearmin = min(arr.at(i * 2)->yearmin, arr.at((i * 2) + 1)->yearmin);
            arr.at(i)->max = max(arr.at(i * 2)->max, arr.at((i * 2) + 1)->max);
            arr.at(i)->min = min(arr.at(i * 2)->min, arr.at((i * 2) + 1)->min);
            arr.at(i)->cont = (arr.at(i * 2)->empty || arr.at((i * 2) + 1)->empty || arr.at(i * 2)->yearmax + 1 == arr.at((i * 2) + 1)->yearmin) && arr.at(i * 2)->cont && arr.at((i * 2) + 1)->cont;
            arr.at(i)->empty = arr.at(i * 2)->empty && arr.at((i * 2) + 1)->empty;          
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
