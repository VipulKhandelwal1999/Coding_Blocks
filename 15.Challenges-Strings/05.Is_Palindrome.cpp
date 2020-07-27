/*
Take as input N, a number. Take N more inputs and store that in an array. Write a recursive function which tests if the array is a palindrome and returns a Boolean value. Print the value returned.

Input Format
Enter a number N , add N more numbers

Constraints
None

Output Format
Display the Boolean result

Sample Input
4
1
2
2
1
Sample Output
true
*/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
bool palindrome(int arr[], int n){
	int flag = 0;
	for(int i=0; i<n/2; i++){
		if(arr[i] != arr[n-i-1]){
			flag = 1;
			break;
		}
	}
	if(flag == 1){
		return false;
	}
	else{
		return true;
	}
}
int main() {
	int n;
	cin >> n;
	int arr[n];
	for(int i=0; i<n; i++){
		cin >> arr[i];
	}
	bool ans = palindrome(arr, n);
	if(ans){
		cout << "true" << endl;
	}
	else{
		cout << "false" << endl;
	}
	return 0;
}
