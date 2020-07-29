/*
Given an array A of size N , write a function that implements insertion sort on the array. Print the elements of sorted array.

Input Format
First line contains a single integer N denoting the size of the array. Next line contains N space seperated integers where ith integer is the ith element of the array.

Constraints
1 <= N <= 1000
|Ai| <= 1000000

Output Format
Output N space seperated integers of the sorted array in a single line.

Sample Input
4
3 4 2 1
Sample Output
1 2 3 4
Explanation
For each test case, write insertion sort to sort the array.
*/

#include<iostream>
using namespace std;

// Insertion Sort
void insertion_sort(int arr[], int n) {

	for (int i = 1; i <= n - 1; i++) {

		int e = arr[i];
		//place the current element at 'right' position in the sorted part
		int j = i - 1;
		while (j >= 0 and arr[j] > e) {
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = e;
	}


}

int main() {

	int n;
	cin >> n;

	int a[n];

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}


	insertion_sort(a, n);
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}


	return 0;

}
