#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin >> n;
	while(n--){
		int x, y, sum=0, digits = 0;
		cin >> x;
		while(x > 0){
			y = x%10;
			if(y==1){
				sum += pow(2,digits);
			}
			digits++;
			x = x/10;
		}
		cout << sum << endl;
	}
	return 0;
}