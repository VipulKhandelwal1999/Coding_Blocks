#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve(vector<ll> &arr, vector<ll> &ans, ll index, ll key){
	if(index == arr.size()){
		return;
	}
	if(arr[index] == key){
		ans.push_back(index);
	}
	solve(arr, ans, index+1, key);
}

int main(){

	ll n;
	cin >> n;
	vector<ll> arr(n, 0);
	for(auto &x: arr)
		cin >> x;
	ll m;
	cin >> m;
	vector<ll> ans;
	solve(arr, ans, 0ll, m);
	for(auto x: ans){
		cout << x << " ";
	}

    return 0;
}