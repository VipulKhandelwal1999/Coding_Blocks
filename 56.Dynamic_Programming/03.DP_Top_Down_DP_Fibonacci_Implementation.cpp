/*
DP - Top Down Approach - Recursion + Memoisation
Time Complexity - O(n)
Space Complexity - O(n) - Internal Stack Space
*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll fib(ll n, ll dp[]){
    //Base case
    if(n == 0 || n == 1){
        return n;
    }
    //Recursive
    //Look Up
    if(dp[n] != 0){
        return dp[n];
    }
    ll ans;
    ans = fib(n-1, dp) + fib(n-2, dp);
    dp[n] = ans;

    return ans;
}

int main() {

    ll n;
    cin >> n;
    ll dp[100] = {0};

    cout << fib(n, dp) << endl;

    return 0;
}
