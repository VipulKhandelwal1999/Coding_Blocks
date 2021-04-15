/*
Right Angled Triangles
Given N points in a 2D Cartesian Plane, How many right angled triangles are there such that
perpendicular or base is parallel to X or Y axis?
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){

    ll n;
    cin >> n;
    unordered_map<ll, ll> arr, brr;
    vector<pair<ll, ll>> counter;
    for(ll i=0; i<n; i++){
        ll x, y;
        cin >> x >> y;
        counter.push_back(make_pair(x, y));
        arr[x]++;
        arr[y]++;
    }
    ll sum = 0;
    for(ll i=0; i<n; i++){
        sum += (arr[counter[i].first]-1)*(arr[counter[i].second]-1);
    }
    cout << sum << "\n";

    return 0;
}
