#include<bits/stdc++.h>
using namespace std;
#define ll long long

//Logic:- dp[pos] < a[i] < dp[pos + 1]
//O(n^2)
int main(){

    int n;
    cin >> n;
    int a[n];
    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    int dp[n+1];
    //lengths from 0-n
    dp[0] = INT_MIN;
    for(int i=1; i<=n; i++){
        dp[i] = INT_MAX;
    }

    for(int i=0; i<n; i++){
        for(int length = 0; length<n; ++length){
            cout << dp[length] << " ";
        }
        cout << endl;
        for(int length = 0; length<n; ++length){
            if(dp[length] < a[i] && a[i] < dp[length + 1]){
                dp[length + 1] = a[i];
            }
        }
        for(int length = 0; length<n; ++length){
            cout << dp[length] << " ";
        }
        cout << endl;
    }

    int lis = 0;
    for(int i=1; i<=n; i++){
        if(dp[i] != INT_MAX){
            lis = i;
        }
    }

    cout << lis;

    return 0;
}
