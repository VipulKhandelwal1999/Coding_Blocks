#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll cont;

void subs(vector<ll> &arr, ll index, ll sum){
	if(index == arr.size()){
		if(sum == 0){
			cont++;
		}
		return;
	}
	subs(arr, index + 1, sum + arr[index]);
	subs(arr, index + 1, sum);
}

int main(){

	ll t;
	cin >> t;
	while(t--){
		cont = 0;
		ll n;
		cin >> n;
		vector<ll> arr(n, 0);
		for(auto &x: arr){
			cin >> x;
		}
		subs(arr, 0ll, 0ll);
		if(cont>=2){
			cout << "Yes\n";
		}
		else{
			cout << "No\n";
		}
	}

	return 0;
}