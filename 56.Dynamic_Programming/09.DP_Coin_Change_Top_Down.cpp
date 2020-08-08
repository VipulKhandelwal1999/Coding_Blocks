#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll minCoins(ll n, ll siz, ll coins[], ll dp[]){

    //Base Case
    if(n == 0){
        return 0;
    }

    //Look Up
    if(dp[n] != 0){
        return dp[n];
    }
    //Recursive Case
    ll mini = INT_MAX;
    for(ll i=0; i<siz; i++){
        if(n >= coins[i]){
            mini = min(mini, minCoins(n-coins[i], siz, coins, dp));
        }
    }
    dp[n] = mini + 1;

    return dp[n];
}

int main() {

    ll coins[] = {1, 5, 10, 20, 50, 100, 200, 500, 2000};
    ll siz = sizeof(coins)/sizeof(coins[0]);
    ll n;
    cin >> n;

    ll dp[100] = {0};

    cout << minCoins(n, siz, coins, dp) << endl;

    return 0;
}
