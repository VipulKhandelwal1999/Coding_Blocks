/*
You are provided n numbers (both +ve and -ve). Numbers are arranged in a circular form. You need to find the maximum sum of consecutive numbers.

Input Format
First line contains integer t which is number of test case.
For each test case, it contains an integer n which is the size of array and next line contains n space separated integers denoting the elements of the array.

Constraints
1<=t<=100
1<=n<=1000
|Ai| <= 10000

Output Format
Print the maximum circular sum for each testcase in a new line.

Sample Input
1
7
8 -8 9 -9 10 -11 12
Sample Output
22
Explanation
Maximum Circular Sum = 22 (12 + 8 - 8 + 9 - 9 + 10)
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
	int t, x;
	cin >> t;
	while(t--)
	{
		int max_so_far = 0, max1, max2;
		int element = 0;
		int sum = 0;
		int n;
		cin >> n;
		int arr[n] = {0};
		for(int i=0; i<n; i++){
			cin >> arr[i];
			sum += arr[i];
		}
		for(int i=0; i<n; i++){
			element += arr[i];
			max_so_far = max(element, max_so_far);
			if(element < 0)
				element = 0;
		}
		max1 = max_so_far;
		max_so_far = 0;
		element = 0;
		for(int i=0; i<n; i++){
			arr[i] = -arr[i];
		}
		for(int i=0; i<n; i++){
			element += arr[i];
			max_so_far = max(element, max_so_far);
			if(element < 0)
				element = 0;
		}
		max2 = sum - (-max_so_far);
		cout << max(max1, max2) << endl;
	}

	return 0;
}
