#include<bits/stdc++.h>
using namespace std;
#define ll long long

void print(string str, string osf, ll index, vector<string> &symbol){
	if(str.size() == index){
		cout << osf << "\n";
		return;
	}
	ll val = str[index] - '0';
	for(auto x: symbol[val]){
		print(str, osf+x, index+1, symbol);
	}
}

int main(){
	vector<string> symbol{ " ", ".+@$", "abc", "def", "ghi", "jkl" , "mno", "pqrs" , "tuv", "wxyz"};
	string str;
	cin >> str;
	string hg = "";
	print(str, hg, 0ll, symbol);

	return 0;
}