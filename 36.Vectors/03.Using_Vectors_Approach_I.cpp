/*
You are at (0,0) in 2D x,y plane. Given (x,y) coordinates of cab. You are at origin. Calculate the distance of each of the cab from origin and print them in sorted order.
*/
#include<bits/stdc++.h>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b){
    int d1 = a.first*a.first + a.second*a.second;
    int d2 = b.first*b.first + b.second*b.second;
    if(d1 != d2)
        return d1<d2;
    else
        return (a.first < b.first);
}

int main(){

    int n;
    cin >> n;
    vector<pair<int, int>> v;
    for(int i=0; i<n; i++){
        int x, y;
        cin >> x >> y;
        v.push_back(make_pair(x,y));
    }
    sort(v.begin(), v.end(), compare);
    for(auto it: v){
        cout << it.first << " " << it.second << endl;
    }
    return 0;
}
