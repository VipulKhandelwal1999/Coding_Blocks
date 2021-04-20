#include<bits/stdc++.h>
using namespace std;
#define ll long long

bool isValid(vector<ll> &arr, ll n){
	if(n==1 || n==0){
		return true;
	}
	if(arr[n-2] <= arr[n-1] && isValid(arr, n-1)){
		return true;
	}
	return false;
}

int main(){

	ll n;
	cin >> n;
	vector<ll> arr(n, 0);
	for(auto &x: arr){
		cin >> x;
	}
	if(isValid(arr, n)){
		cout << "true\n";
	}
	else{
		cout << "false\n";
	}

	return 0;
}