#include<bits/stdc++.h>
using namespace std;
#define ll long long

void subs(string str, string & osf, ll index){
	if(str.size()==index)
		return;
	if(str[index] != 'x'){
		osf += str[index];
	}
	subs(str, osf, index + 1);
}

int main(){

	string str;
	cin >> str;
	ll index = 0;
	string osf = "";
	subs(str, osf, 0ll);
	cout << osf;
	ll len = str.size() - osf.size();
	for(ll i=0; i<len; i++){
		cout << 'x';
	}
	return 0;
}