/*
Take as input N, the size of array. Take N more inputs and store that in an array. Write a function which returns the maximum value in the array. Print the value returned.

1.It reads a number N.

2.Take Another N numbers as input and store them in an Array.

3.calculate the max value in the array and return that value.

Input Format
First line contains integer n as size of array. Next n lines contains a single integer as element of array.

Constraints
N cannot be Negative. Range of Numbers can be between -1000000000 to 1000000000

Output Format
Print the required output.

Sample Input
4
2
8
6
4
Sample Output
8
Explanation
Arrays= {2, 8, 6, 4} => Max value = 8 .

Logic:-
For the case arr= {20, 10, 20, 4, 100}, max element is 100.

Time complexity : o(n), where n is the size of the array. Worst case is when max element is present at the end of the array.

Algorithm:
1.Initialize max variable with minimum value of integer or with 0th element of the array say arr.
2.Iterate over each element of the array
2.1 if arr[i] > max then // updating max when the array element at ith location is greater than max
max=arr[i]
3.After end of the loop max is having the maximum element of the array.
4.Print max.
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
	long long n, max, x;
	cin >> n;
	cin >> max;
	for(int i=0; i<n-1; i++){
		cin >> x;
		if(max < x)
			max = x;
	}
	cout << max;
	return 0;
}
