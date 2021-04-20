#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll stringToInt(string a, ll n){
    if(n == 0)
        return 0ll;
    ll digit = a[n-1] - '0';
    ll small_ans = stringToInt(a, n-1);
    return small_ans*10 + digit;
}

int main(){

	string str;
	cin >> str;
	ll len = str.size();
	ll ans = stringToInt(str, len);
	cout << ans << "\n";

	return 0;
}