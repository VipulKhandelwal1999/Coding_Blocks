#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll maxSum(ll a[], ll n){

    ll dp[100] = {0};
    dp[0] = a[0] > 0 ? a[0] : 0;
    ll max_so_far = dp[0];

    //Linear Time
    for(ll i=1; i<n; i++){
        dp[i] = dp[i-1] + a[i];
        if(dp[i] < 0){
            dp[i] = 0;
        }
        max_so_far = max(max_so_far, dp[i]);
    }
    return max_so_far;
}

int main(){

    ll arr[] = {-3, 2, 5, -1, 6, 3, -2, 7, -5, 2};
    ll n = sizeof(arr)/sizeof(arr[0]);

    cout << maxSum(arr, n) << endl;

    return 0;
}
