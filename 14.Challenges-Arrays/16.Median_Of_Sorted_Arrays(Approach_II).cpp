/*
We are given two sorted arrays of same size n. Find the median of an array formed after merging these two sorted arrays.

Input Format
First line contains the input n. Second and Third line contains n space separated integers.

Constraints
N < 1000

Output Format
Print the median in a single line.

Sample Input
5
1 3 5 7 9
2 4 6 8 10
Sample Output
5
Explanation
Merged Array: [ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10] So the median element is 5
*/

#include<bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin >> n;
	int arr[n], brr[n], a[2*n];
	for(int i=0; i<n; i++){
		cin >> arr[i];
	}
	for(int i=0; i<n; i++){
		cin >> brr[i];
	}
	int i=0;
	int j=0;
	int k = 0;
	while(i<n && j<n){
		if(arr[i]>brr[j]){
			a[k] = brr[j];
			k++;
			j++;
		}
		else{
			a[k] = arr[i];
			i++;
			k++;
		}
	}
	while(i<n){
		a[k] = arr[i];
		i++;
		k++;
	}
	while(j<n){
		a[k] = brr[j];
		j++;
		k++;
	}
	cout << a[n-1];
	return 0;
}
