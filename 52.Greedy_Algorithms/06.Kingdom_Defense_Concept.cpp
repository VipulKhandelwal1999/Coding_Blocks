// Link:- https://www.spoj.com/problems/DEFKIN/

#include<bits/stdc++.h>
using namespace std;
#define ll long long

bool comp(pair<ll, ll> x, pair<ll, ll> y){
    return x.second < y.second;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while(t--){
        ll w, h, n;
        cin >> w >> h >> n;
        if(n==0){
            cout << w*h << "\n";
        }
        else{
            vector<pair<ll, ll>> arr;
            for(ll i=0; i<n; i++){
                ll x, y;
                cin >> x >> y;
                arr.push_back(make_pair(x, y));
            }
            sort(arr.begin(), arr.end());
            ll start = 0, maxiX = 0, maxiY = 0;
            for(ll i=0; i<n; i++){
                maxiX = max(maxiX, arr[i].first - start-1);
                start = arr[i].first;
            }
            maxiX = max(maxiX, w-arr[n-1].first);
            sort(arr.begin(), arr.end(), comp);
            start = 0;
            for(ll i=0; i<n; i++){
                maxiY = max(maxiY, arr[i].second - start-1);
                start = arr[i].second;
            }
            maxiY = max(maxiY, h-arr[n-1].second);
            cout << maxiX*maxiY << "\n";
        }
    }

    return 0;
}