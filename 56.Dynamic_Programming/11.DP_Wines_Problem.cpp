#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll profit(ll wines[], ll i, ll j, ll y, ll dp[][100]){
    //Base Case
    if(i > j){
        return 0;
    }
    //LookUp
    if(dp[i][j] != 0){
        return dp[i][j];
    }

    //Recursive Case
    ll op1 = wines[i]*y + profit(wines, i+1, j, y+1, dp);
    ll op2 = wines[j]*y + profit(wines, i, j-1, y+1, dp);
    dp[i][j] = max(op1, op2);
    return dp[i][j];
}
int main(){

    ll wines[] = {2, 3, 5, 1, 4};
    ll dp[100][100] = {0};
    ll n = sizeof(wines) / sizeof(wines[0]);
    ll y = 1;
    cout << profit(wines, 0, n-1, y, dp) << endl;

    return 0;
}
