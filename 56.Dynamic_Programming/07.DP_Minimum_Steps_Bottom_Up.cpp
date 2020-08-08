/*
Minimum number of steps to reach from n to 1.We can take one of the steps given below in each steps
1.n = n/3 if n%3 == 0
2.n = n/2 if n%2 == 0
3.n = n-1
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll minSteps(ll n, ll dp[]){

    for(ll i=2; i<=n; i++){

        ll op1, op2, op3;
        op1 = op2 = op3 = INT_MAX;

        if(i%3 == 0){
            op1 = dp[i/3];
        }
        if(i%2 == 0){
            op2 = dp[i/2];
        }
        op3 = dp[i-1];
        dp[i] = min(min(op1, op2), op3) + 1;
    }
    return dp[n];
}

int main() {

    ll n;
    cin >> n;

    ll dp[100] = {0};
    cout << minSteps(n, dp) << endl;

    return 0;
}
