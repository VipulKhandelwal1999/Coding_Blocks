#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll minCoins(ll n, ll siz, ll coins[]){

    //Base Case
    if(n == 0){
        return 0;
    }

    //Recursive Case
    ll mini = INT_MAX;
    for(ll i=0; i<siz; i++){
        if(n >= coins[i]){
            mini = min(mini, minCoins(n-coins[i], siz, coins));
        }
    }
    return mini + 1;
}

int main() {

    ll coins[] = {1, 5, 10, 20, 50, 100, 200, 500, 2000};
    ll siz = sizeof(coins)/sizeof(coins[0]);
    ll n;
    cin >> n;

    cout << minCoins(n, siz, coins) << endl;

    return 0;
}
