#include <bits/stdc++.h>
using namespace std;

double calc_distance_sq(double x1, double y1, double x2, double y2){
    return pow((x2-x1), 2) + pow((y2-y1), 2);
}

void ternary_search(vector<pair<double, double>>& points, double minx, double maxx){
    double minm1 = DBL_MIN;
    double minm2 = DBL_MIN;
    while(maxx - minx > 0.000001) {
        //cout << fixed << setprecision(10) << "Max min: " << minx << " " <<  maxx <<endl;
        minm1 = DBL_MIN;
        minm2 = DBL_MIN;

        double m1 = minx + (maxx - minx) / 3.0;
        double m2 = maxx - (maxx - minx) / 3.0;
        
        for(int i = 0; i < points.size(); i++){
            minm1 = max(minm1, calc_distance_sq(m1, 0, points.at(i).first, points.at(i).second));
            minm2 = max(minm2, calc_distance_sq(m2, 0, points.at(i).first, points.at(i).second));
        }
        //cout << fixed << setprecision(10) << "  " << minm1 << " " << minm2 << endl;
        if(minm1 < minm2) {
            maxx = m2;
        } else {
            minx = m1;
        } 
    }
    cout << fixed << setprecision(12) << minx << " " << abs(sqrt(minm1)) << endl;
}

int main(){
    long long n;
    
    while(cin >> n){
        vector<pair<double, double>> points;
        double x, y;
        double minx = DBL_MAX;
        double maxx = DBL_MIN;
        if(n == 0){
            break;
        } else if(n == 1){
            cin >> x >> y;
            cout << fixed << setprecision(12) << x << " " << abs(y) << endl;
            continue;
        } else {
            for(int i = 0; i < n; i++){
                cin >> x >> y;
                points.push_back({x, y});
                minx = min(minx, x);
                maxx = max(maxx, x);
            }
            minx = -1e9;
            maxx = 1e9;
            ternary_search(points, minx, maxx);
        }
    }
    
    return 0;
}
