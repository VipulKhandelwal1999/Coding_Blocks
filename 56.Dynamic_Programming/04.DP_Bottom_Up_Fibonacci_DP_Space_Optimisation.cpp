/*
DP - Bottom Up Approach - Array + Bottom Up Approach (Space Optimised)
Time Complexity - O(n)
Space Complexity - O(n)
*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll fib(ll n, ll dp[]){

    if(n > 1){
        for(ll i=2; i<=n; i++){
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
    else{
        return dp[n];
    }
}

//Bottom Up Approach With Space Optimisation
ll fibSpaceOptimised(ll n){

    if(n==0 or n==1){
        return n;
    }

    ll a = 0;
    ll b = 1;
    ll c;
    for(ll i=2; i<=n; i++){
        c = a+b;
        a = b;
        b = c;
    }

    return c;
}

int main() {

    ll n;
    cin >> n;

    ll dp[100] = {0};
    dp[1] = 1;

    cout << fib(n, dp) << endl;

    cout << fibSpaceOptimised(n) << endl;

    return 0;
}
