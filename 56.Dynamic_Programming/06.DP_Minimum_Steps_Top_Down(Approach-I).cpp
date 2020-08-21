/*
Minimum number of steps to reach from n to 1.We can take one of the steps given below in each steps
1.n = n/3 if n%3 == 0
2.n = n/2 if n%2 == 0
3.n = n-1
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll stepsTopDown(ll n, ll dp[]){
    if(n == 1)
        return 0;
    if(n%3 == 0){
        if(dp[n/3] != 0 && dp[n-1] != 0){
            ll ans = min(dp[n/3], dp[n-1]) + 1;
            dp[n] = ans;
            return ans;
        }
        ll ans = min(stepsTopDown(n/3, dp), stepsTopDown(n-1, dp))+1;
        dp[n] = ans;
        return ans;
    }
    else if(n%2==0){
        if(dp[n/2] != 0 && dp[n-1] != 0){
            ll ans = min(dp[n/2], dp[n-1]) + 1;
            dp[n] = ans;
            return ans;
        }
        ll ans = min(stepsTopDown(n/2, dp), stepsTopDown(n-1, dp))+1;
        dp[n] = ans;
        return ans;
    }
    else{
        if(dp[n-1] != 0){
            dp[n] = dp[n-1] + 1;
            return dp[n];
        }
        dp[n] = stepsTopDown(n-1, dp)+1;
        return dp[n];
    }
}

int main() {

    ll n;
    cin >> n;
    ll dp[100] = {0};
    cout << stepsTopDown(n, dp) << endl;

    return 0;
}
