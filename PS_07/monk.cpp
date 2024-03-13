#include <bits/stdc++.h>
using namespace std;

struct segment{
    long long x1;
    long long y1;
    long long x2;
    long long y2;
};

bool check_intersection(segment s1, segment s2){
    long long xcoef1 = s1.y2 -  s1.y1;
    long long ycoef1 = s1.x1 -  s1.x2;
    long long const1 = (xcoef1 * s1.x1) + (ycoef1 * s1.y1);
    long long xcoef2 = s2.y2 -  s2.y1;
    long long ycoef2 = s2.x1 -  s2.x2;
    long long const2 = (xcoef2 * s2.x1) + (ycoef2 * s2.y1);

    long double det = xcoef1 * ycoef2 - xcoef2 * ycoef1;
    if (det == 0) {
        //cout << "Det == 0: " << s1.y1 << " " << s2.y1 << " --- " << s1.y2 << " " << s2.y2 << endl;
        if((s1.x1 == s2.x1 && s1.y2 >= s2.y1 )|| s1.y1 == s2.y2 || s1.y2 == s2.y1){
            cout << fixed << setprecision(6) << max(s1.x1, s2.x1) << endl;
            return true;
        }
        return false;
    }
    long double x = (ycoef2 * const1 - ycoef1 * const2) / det;
    long double y = (xcoef1 * const2 - xcoef2 * const1) / det;

    //cout << "   " << x << " " << y <<endl;
    
    if(x < max(s1.x1, s2.x1) || x > min(s1.x2, s2.x2)){
        return false;
    }

    cout << fixed << setprecision(6) << x << endl;
    return true;
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
        acscent.push_back(segment{time, height, time + t, height + h});
        //cout << height << " " << time << " " << height + h << " " <<  time + t << endl;
        height += h;
        time += t;
    }
    time = 0;
    for(long long i = 0; i < d; i++){  
        long long h, t;
        cin >> h >> t;
        descent.push_back(segment{time, height, time + t, height - h});
        //cout << height << " " << time << " " << height - h << " " <<  time + t << endl;
        height -= h;
        time += t;
    }
    long long up = 0;
    long long down = 0;

    while(down < descent.size() && up < acscent.size()){
        if(descent.at(down).y1 > acscent.at(up).y1 && descent.at(down).y2 > acscent.at(up).y2){
            up++;
            down++;
        } else {
            if(check_intersection(descent.at(down), acscent.at(up))){
                break;
            } else if(descent.at(down).x2 > acscent.at(up).x2){
                up++;
            } else {
                down++;
            }
        }
    }


    return 0;
}
