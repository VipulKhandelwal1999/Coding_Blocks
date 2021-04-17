#include<bits/stdc++.h>
using namespace std;
#define ll long long

void multiply(vector<ll> &ans, ll num){
    ll carry = 0;
    for(ll i=0; i<ans.size(); i++){
        ll val = num*ans[i] + carry;
        carry = val/10;
        ans[i] = val%10;
    }
    while(carry > 0){
        ans.push_back(carry%10);
        carry /= 10;
    }
}

vector<ll> factorial(ll n){
    vector<ll> ans;
    ans.push_back(1ll);
    for(ll i=2; i<=n; i++){
        multiply(ans, i);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main(){

    ll t = 1;
    // cin >> t;
    while(t--){
        ll n;
        cin >> n;
        vector<ll> ans = factorial(n);
        for(auto x: ans){
            cout << x;
        }
        cout << "\n";
    }

    return 0;
}