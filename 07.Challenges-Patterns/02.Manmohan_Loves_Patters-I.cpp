/*

Given N, help Manmohan to print pattern upto N lines. For eg For N=6 , following pattern will be printed.

1
11
111
1001
11111
100001

Input Format
Single number N.

Constraints
N<=1000

Output Format
Pattern corresponding to N.

Sample Input
6
Sample Output
1
11
111
1001
11111
100001
Explanation
For every odd number row print 1, odd number of times and for every even number row , print first and last character as 1 and rest of middle characters as 0.

*/


#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	if(n==1){
		cout << "1";
	}
	else{
		for(int i=1; i<=n; i++){
			if(i%2!=0){
				for(int j=1; j<=i; j++){
					cout << "1";
				}
				cout << endl;
			}
			else{
				cout << "1";
				for(int j=1; j<=i-2; j++){
					cout << "0";
				}
				cout << "1" << endl;
			}
		}
	}
	return 0;
}
