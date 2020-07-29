/*
We are given an array containg n numbers. All the numbers are present twice except for two numbers which are present only once. Find the unique numbers in linear time without using any extra space. ( Hint - Use Bitwise )

Input Format
First line contains the number n. Second line contains n space separated number.

Constraints
n < 10^5

Output Format
Output a single line containing the unique numbers separated by space

Sample Input
4
3 1 2 1
Sample Output
2 3
Explanation
Smaller number comes before larger number
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {

	int arr[100000];
	int n;
	cin >> n;
	int sum = 0;
	for(int i=0; i<n; i++){
		cin >> arr[i];
		sum ^= arr[i];
	}
	int mask = sum & (-sum);  //way to find lowbit
	int qr = 0;
	int xy = 0;
	for(int i=0; i<n; i++){
		if(arr[i] & mask > 0){
			qr ^= arr[i];
		}
		else
			xy ^= arr[i];

	}
	cout << min(xy,qr) << " " << max(xy,qr);

	return 0;
}
