#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve(string input, string output, unordered_map<string, char> &mapper){
	if(input.size()==0){
		cout << output << "\n";
		return;
	}
	 for(ll i=1; i<=input.size(); i++){
		 string str = input.substr(0, i);
		//  cout << str << "\n";
		 if(mapper.find(str) != mapper.end()){
			solve(input.substr(i), output + mapper[str], mapper);
		 }
		 else{
			 break;
		 }
	 }
}

int main(){

	string n;
	cin >> n;
	char c = 65;
	unordered_map<string, char> mapper;
	for(ll i=1; i<=26; i++){
		string str = to_string(i);
		mapper[str] = c;
		c++;
	}

	string str =  "";
	solve(n, str, mapper);

	return 0;
}