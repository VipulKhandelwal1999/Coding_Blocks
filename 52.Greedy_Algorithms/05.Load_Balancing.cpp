// Link:- https://www.spoj.com/problems/BALIFE/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

int main(){
    while(true){
        ll n;
        cin >> n;
        if(n==-1)
            return 0;
        vector<ll> arr(n, 0);
        ll sum = 0;
        for(auto &x: arr){
            cin >> x;
            sum += x;
        }
        ld y = sum/(ld)n;
        if(y == (ll)y){
            ll ans = 0;
            for(ll i=1; i<n; i++){
                arr[i] = arr[i] + arr[i-1];
            }
            for(ll i=1; i<n; i++){
                ll x = arr[i-1];
                ll z = y*(i);
                ll r = abs(z-x);
                ans = max(ans, r);
            }
            cout << ans << "\n";
        }
        else{
            cout << "-1\n";
        }
    }

    return 0;
}