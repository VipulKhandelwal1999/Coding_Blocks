#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll solveCellProblem(ll n, ll x, ll y, ll z){
    ll dp[n] = {0};
    //Bottom Up DP
    dp[0] = 0;
    dp[1] = 0;

    for(ll i=2; i<=n; i++){
        if(i%2 == 0){
            dp[i] = min(dp[i/2] + x, dp[i-1] + y);
        }
        else{
            dp[i] = min(dp[i-1] + y, dp[(i+1)/2]+z);
        }
    }
    return dp[n];
}

int main(){

    ll n, x, y, z;
    cin >> n >> x >> y >> z;

    cout << solveCellProblem(n, x, y, z) << endl;

    return 0;
}
