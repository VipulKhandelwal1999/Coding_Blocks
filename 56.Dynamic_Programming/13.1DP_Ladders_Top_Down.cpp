#include<bits/stdc++.h>
using namespace std;

int ladders_topdown(int n, int k, int dp[]){
    //base case
    if(n == 0)
        return 1;

    //lookup
    if(dp[n] != 0){
        return dp[n];
    }

    //rec case
    int ways = 0;
    for(int i=1; i<=k; i++){
        if(n-i >= 0){
            ways += ladders_topdown(n-i, k, dp);
        }
    }
    dp[n] = ways;
    return dp[n];
}

int main() {

    int n, k;
    int dp[100] = {0};
    cin >> n >> k;
    cout << "Ways " << ladders_topdown(n, k, dp) << endl;


    return 0;
}
