/*
You are given an array, A. Sort this array using counting sort algorithm.

Input Format
First line contains a single integer, n, denoting the size of the array. Next line contains n integers, denoting the elements of the array.

Constraints
1<=N<=10^6 0<=Ai<=10^6

Output Format
Print the array in sorted order.

Sample Input
5
1 3 2 6 5
Sample Output
1 2 3 5 6
*/

#include<bits/stdc++.h>
using namespace std;
long long arr[1000001] = {0};

int main() {

	long long n;
	cin >> n;
	long long maxi = INT_MIN;

	for(long long i=0; i<n; i++){
		long long x;
		cin >> x;
		maxi = max(maxi, x);
		arr[x]++;
	}
	for(long long i=0; i<=maxi; i++){
		while(arr[i] != 0){
			cout << i << " ";
			arr[i]--;
		}
	}

	return 0;
}
