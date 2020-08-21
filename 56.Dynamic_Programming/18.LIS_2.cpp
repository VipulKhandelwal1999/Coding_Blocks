#include<bits/stdc++.h>
using namespace std;
#define ll long long

//Longest Increasing Subsequence O(n^2)

int main(){

    int n;
    cin >> n;
    int a[n] = {0};
    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    int dp[n] = {0};

    for(int i=0; i<n; i++){
        dp[i] = 1; //Every element can end at length 1
        for(int j=0; j<i; j++){
            if(a[j] < a[i])
                dp[i] = max(dp[i], dp[j] + 1);
        }
    }
    int lis = 0;
    for(int i=0; i<n; i++){
        lis = max(lis, dp[i]);
    }
    cout << lis << endl;

    return 0;
}
