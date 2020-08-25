#include<bits/stdc++.h>
using namespace std;

int ans(vector<int> &a){
    int dp[200][200];
    memset(dp, 0, sizeof dp);
    int n = A.size() - 1;
    for(int i=1; i<n; i++){
        int r = 0, c = i;
        while(c < n){
            int val = INT_MAX;
            for(int pivot = r; pivot < c; pivot++){
                val = min(val, dp[r][pivot] + dp[pivot-1][c]);
            }
            dp[r][c] = val;
            r++, c++;
        }
    }
    return dp[0][n-1];
}
