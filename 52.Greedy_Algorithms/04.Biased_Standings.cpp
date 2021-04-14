// Link:- https://www.spoj.com/problems/BAISED/

#include<bits/stdc++.h>
using namespace std;
#define ll long long

bool comp(pair<string, ll> a, pair<string, ll> b){
    return a.second < b.second;
}

int main(){

    ll t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        vector<pair<string, ll>> arr;
        for(ll i=0; i<n; i++){
            string str;
            ll y;
            cin >> str >> y;
            arr.push_back(make_pair(str, y));
        }
        sort(arr.begin(), arr.end(), comp);
        ll sum = 0;
        ll count = 1;
        for(ll i=0; i<n; i++){
            sum += abs(arr[i].second - count);
            count++;
        }
        cout << sum << "\n";
    }

    return 0;
}