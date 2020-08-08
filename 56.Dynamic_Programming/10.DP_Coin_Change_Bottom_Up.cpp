#include<bits/stdc++.h>
using namespace std;
#define ll long long

void minCoins(ll n, ll siz, ll coins[], ll dp[]){

    //Iterative Case
    ll mini = INT_MAX;
    for(ll i=0; i<siz; i++){
        if(n >= coins[i]){
            mini = min(mini, dp[n-coins[i]]);
        }
    }
    dp[n] = mini + 1;
}

int main() {

    ll coins[] = {1, 5, 10, 20, 50, 100, 200, 500, 2000};
    ll siz = sizeof(coins)/sizeof(coins[0]);
    ll n;
    cin >> n;

    ll dp[3000] = {0};
    for(ll i=1; i<=n; i++){
        minCoins(i, siz, coins, dp);
    }
    cout << dp[n] << endl;

    return 0;
}
