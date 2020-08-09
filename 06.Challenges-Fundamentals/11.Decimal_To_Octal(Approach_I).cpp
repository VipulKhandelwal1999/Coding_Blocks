/*
Take N (number in decimal format). Write a function that converts it to octal format. Print the value returned.

Input Format
Constraints
0 < N <= 1000000000

Output Format
Sample Input
63
Sample Output
77
Explanation
Both input and output are integers
*/

#include<bits/stdc++.h>
using namespace std;

int main() {
	long long n;
	vector<int> v;
	cin >> n;
	while(n>0){
		v.push_back(n%8);
		n = n/8;
	}
	for(auto it=v.rbegin(); it!=v.rend(); ++it)
	{
		cout << *it;
	}
	return 0;
}
