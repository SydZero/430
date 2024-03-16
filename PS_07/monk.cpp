#include <bits/stdc++.h>
using namespace std;

struct segment{
    long long x1;
    long long y1;
    long long x2;
    long long y2;
    double slope;
};

double f(double x, vector<segment>& graph){
    for(segment s : graph){
        if(s.x1 <= x && x <= s.x2){
            return s.y1 + ((x - s.x1) * s.slope);
        }
    }
    return graph.back().y2;
}

int main(){
    long long a, d;
    cin >> a >> d;
    long long height = 0;
    long long time = 0;
    vector<segment> acscent;
    vector<segment> descent;
    
    for(long long i = 0; i < a; i++){  
        long long h, t;
        cin >> h >> t;
        acscent.push_back(segment{time, height, time + t, height + h, (1.0 * h) / (1.0 * t)});
        //cout << height << " " << time << " " << height + h << " " <<  time + t << endl;
        height += h;
        time += t;
    }
    long long mheight = height;
    time = 0;
    for(long long i = 0; i < d; i++){  
        long long h, t;
        cin >> h >> t;
        descent.push_back(segment{time, height, time + t, height - h, (-1.0 * h) / (1.0 * t)});
        height -= h;
        time += t;
    }

    double left = 0;
    double right = DBL_MAX;
    double m = (left + right) / 2.0;

    while(abs(left - right) > .0000001){
        m = ((left + right) / 2.0);
        
        double a = f(m, acscent);
        double d = f(m, descent);
        //cout << fixed << setprecision(12) << "TESTING: " << m << endl;
        //cout << a << " " << d << endl;
        if(a >= d) {
            right = m;
        } else {
            left = m;
        }
    }
    cout << fixed << setprecision(6) << left << endl;
    
    return 0;
}
