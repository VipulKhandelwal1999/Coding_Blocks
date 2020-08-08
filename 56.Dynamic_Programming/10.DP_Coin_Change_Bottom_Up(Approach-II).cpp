#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll minCoins(ll N, ll coins[], ll T){
    ll dp[100] = {0};

    //Iterative Over all the states 1...N
    for(ll n=1; n<=N; n++){
        //Init the current ans as INT_MAX
        dp[n] = INT_MAX;

        for(ll i=0; i<T; i++){
            if(n >= coins[i]){
                ll subprob = dp[n-coins[i]];
                dp[n] = min(dp[n], subprob+1);
            }
        }
    }
    return dp[N];
}

int main() {

    ll n = 15;
    ll coins[] = {1, 7, 10};
    ll T = sizeof(coins)/sizeof(coins[0]);

    cout << minCoins(n, coins, T) << endl;

    return 0;
}
