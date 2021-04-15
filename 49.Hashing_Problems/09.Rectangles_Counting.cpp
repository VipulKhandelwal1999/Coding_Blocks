#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Point{
    public: 
        ll x, y;
        Point(){

        }
        Point(ll x, ll y){
            this->x = x;
            this->y = y;
        }
};

class Compare{
    public:
        bool operator()(Point p1, Point p2){
            if(p1.x == p2.x){
                return p1.y < p2.y;
            }
            return p1.x < p2.x;
        }
};

ll countRects(vector<Point> coords){
    ll n = coords.size();
    // insert all points in the set
    set<Point, Compare> s;
    for(auto p: coords){
        s.insert(p);
    }
    ll ans = 0;
    for(auto it=s.begin(); it!=prev(s.end()); it++){
        for(auto jt=next(it); jt!=s.end(); jt++){
            Point p1 = *it;
            Point p2 = *jt;
            if(p1.x==p2.x or p1.y==p2.y){
                continue;
            }
            Point p3(p2.x, p1.y);
            Point p4(p1.x, p2.y);
            if(s.find(p3)!=s.end() and s.find(p4)!=s.end()){
                ans++;
            }
        }
    }
    return ans;
}

int main(){

    ll m;
    cin >> m;
    vector<Point> coords;
    while(m--){
        ll x, y;
        cin >> x >> y;
        Point p(x, y);
        coords.push_back(p);
    }
    ll ans = countRects(coords);
    ans /= 2; // Each Point Counted Twice
    cout << ans;

    return 0;
}


/*
Input:
8
0 0
0 1
1 1
1 0 
2 1
2 0
3 1
3 0

Output:
6
*/