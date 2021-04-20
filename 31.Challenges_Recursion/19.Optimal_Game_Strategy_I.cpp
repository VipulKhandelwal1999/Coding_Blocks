#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll dp[31][31];
ll solve(ll i, ll j, vector<ll> &arr){
	if(i==j){
		return dp[i][j] = arr[i];
	}
	if(i>j){
		return dp[i][j] = 0ll;
	}
	ll x = arr[i] + min(solve(i+2, j, arr), solve(i+1, j-1, arr));
	ll y = arr[j] + min(solve(i+1, j-1, arr), solve(i, j-2, arr));
	ll ans = max(x, y);
	return dp[i][j] = ans;
}

int main(){
	memset(dp, -1, sizeof(dp));
	ll n;
	cin >> n;
	vector<ll> arr(n, 0);
	for(auto &x: arr){
		cin >> x;
	}
	cout << solve(0ll, arr.size()-1, arr);

	return 0;
}