#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll solve(vector<ll> &arr, ll m, ll index){
	if(index<0){
		return -1;
	}
	if(arr[index] == m){
		return index;
	}
	return solve(arr, m, index-1);
}

int main(){

	ll n;
	cin >> n;
	vector<ll> arr(n, 0);
	for(auto &x: arr)
		cin >> x;
	ll m;
	cin >> m;
	ll index = n-1;
	ll ans = solve(arr, m, index); 
	cout << ans << "\n";

	return 0;
}