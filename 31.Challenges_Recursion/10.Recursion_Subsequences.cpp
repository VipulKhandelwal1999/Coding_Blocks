#include<bits/stdc++.h>
using namespace std;
#define ll long long
void subs(string str, string osf, ll &count){

	if(str.size()==0){
		count++;
		cout << osf << " ";
		return;
	}
	subs(str.substr(1), osf, count);
	subs(str.substr(1), osf + str[0], count);

}

int main(){

	string str;
	cin >> str;
	string osf = "";
	ll count = 0;
	subs(str, osf, count);
	cout << "\n" << count << "\n";
	return 0;
}