/*
You will be given an array containing only 0s, 1s and 2s. you have sort the array in linear time that is O(N) where N is the size of the array.

Input Format
The first line contains N, which is the size of the array. The following N lines contain either 0, or 1, or 2.

Constraints
1 <= N <= 10^6
Each input element x, such that x ∈ { 0, 1, 2 }.

Output Format
Output the sorted array with each element separated by a newline.

Sample Input
5
0
1
2
1
2
Sample Output
0
1
1
2
2
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {

	int n;
	cin >> n;
	int arr[3] = {0};
	for(int i=0; i<n; i++){
		int x;
		cin >> x;
		arr[x]++;
	}
	for(int i=0; i<3; i++){
		while(arr[i] != 0){
			cout << i << endl;
			arr[i]--;
		}
	}

	return 0;
}
