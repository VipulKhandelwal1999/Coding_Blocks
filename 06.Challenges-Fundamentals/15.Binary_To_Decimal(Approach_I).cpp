/*
Take N (number in binary format). Write a function that converts it to decimal format and Print the value returned.

Input Format
Constraints
0 < N <= 1000000000

Output Format
Sample Input
101010
Sample Output
42
Explanation
For binary number fedcba , Decimal number = f * 2^5 + e * 2^4 + d * 2^3 + …..+ a * 20.
*/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
	int n, sum = 0, count = 0;
	cin >> n;
	while(n>0){
		sum = sum + ((n%10) << count);
		count++;
		n /= 10;
	}
	cout << sum << endl;
	return 0;
}
