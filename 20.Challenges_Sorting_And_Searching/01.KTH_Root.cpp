/*
You are given two integers n and k. Find the greatest integer x, such that, x^k <= n.

Input Format
First line contains number of test cases, T. Next T lines contains integers, n and k.

Constraints
1<=T<=10
1<=N<=10^15
1<=K<=10^4

Output Format
Output the integer x

Sample Input
2
10000 1
1000000000000000 10
Sample Output
10000
31
Explanation
For the first test case, for x=10000, 10000^1=10000=n
*/

#include<bits/stdc++.h>
using namespace std;
int main() {
	long long t;
	cin >> t;
	while(t--){
		long long n, k;
		cin >> n >> k;
		long long x = 0;
		long long low = 1;
		long long high = n;
		while(low <= high){
			long long mid = (low+high)/2;
			if(pow(mid, k) <= n){
				x = mid;
				low = mid+1;
			}
			else
				high = mid-1;
		}
		cout << x << endl;
	}
	return 0;
}
