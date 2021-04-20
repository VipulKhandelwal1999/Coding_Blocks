#include<bits/stdc++.h>
using namespace std;
#define ll long long

void conString(string &str, ll index){
	if(index==0){
		return;
	}
	if(str[index] == str[index-1]){
		str.insert(index, "*");
	}
	conString(str, index-1);
}

int main(){

	string str;
	cin >> str;
	ll index = str.size()-1;
	conString(str, index);
	cout << str << "\n";

	return 0;
}