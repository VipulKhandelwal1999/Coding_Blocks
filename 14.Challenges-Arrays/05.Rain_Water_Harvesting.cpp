/*
Apoorvaa has created an elevated roof. She wants to know how much water can she save during rain.

Given n non negative integers representing the elevation map where width of every bar is 1, Find the maximum water that she can save.

Explanation for the Sample input Testcase:
Elevation Map

So the total units of water she can save is 5 units

Input Format
First line contains an integer n. Second line contains n space separated integers representing the elevation map.

Constraints
1 <= N <= 10^6

Output Format
Print a single integer containing the maximum unit of waters she can save.

Sample Input
10
0 2 1 3 0 1 2 1 2 1
Sample Output
5
Explanation
Refer to the image for explanation. Count the number of cells having water in them.
*/

#include<bits/stdc++.h>
using namespace std;
int a[1000000], l[1000000], r[1000000];

int main()
{
	int n, i, j;
	cin >> n;
	for (i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	l[0] = a[0];
	r[n - 1] = a[n - 1];
	for (i = 1; i < n; i++)
	{
		l[i] = max(l[i - 1], a[i]);
	}
	for (i = n - 2; i >= 0; i--)
	{
		r[i] = max(r[i + 1], a[i]);
	}
	int water = 0;
	for (i = 0; i < n; i++)
	{
		water += (min(l[i], r[i]) - a[i]);
	}
	cout << water;
	return 0;
}
