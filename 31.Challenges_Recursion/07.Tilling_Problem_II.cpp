#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
ll dp[100001];
ll ways(ll n, ll m){
	if(dp[n] != -1){
		return dp[n];
	}
	if(n<m){
		return dp[n] = 1ll;
	}
	
	return dp[n] = (ways(n-1, m)%mod + ways(n-m, m)%mod)%mod;
}

int main(){

	ll t;
	cin >> t;
	while(t--){
		memset(dp, -1, sizeof(dp));
		ll n, m;
		cin >> n >> m;
		ll ans = ways(n, m);
		cout << dp[n] << "\n";
	}

	return 0;
}