#include<bits/stdc++.h>
using namespace std;

int memo[100] = {0};

int maxProfit(int arr[], int totalLen){
    if(totalLen == 0)
        return 0;

    if(memo[totalLen] != 0){
        return memo[totalLen];
    }

    int best = 0;
    for(int len = 1; len<=totalLen; ++len){
        int netProfit = arr[len] + maxProfit(arr, totalLen - len);
        best = max(best, netProfit);
    }
    memo[totalLen] = best;
    return best;
}

int maxProfitBu(int arr[], int totalLen){
    int dp[100] = {0};

    for(int len = 1; len <= totalLen; len++){
        int best = 0;
        for(int cut=1; cut <= len; cut++){
            dp[len] = arr[cut] + dp[len - cut];
            best = max(best, dp[len]);
        }
        dp[len] = best;
    }
    return dp[totalLen];
}

int main() {

    int price[100];
    int totalLen;
    cin >> totalLen;
    for(int eachPiece = 1; eachPiece <= totalLen; ++eachPiece){
        cin >> price[eachPiece];
    }

    int ans = maxProfit(price, totalLen);
    cout << ans << endl;

    return 0;
}
