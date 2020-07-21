/*
Take as input S, a string. Write a function that returns the character with maximum frequency. Print the value returned.

Input Format
String

Constraints
A string of length between 1 to 1000.

Output Format
Character

Sample Input
aaabacb
Sample Output
a
Explanation
For the given input string, a appear 4 times. Hence, it is the most frequent character.
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
	int arr[26] = {0};
	char ch;
	int maxim = INT_MIN;
	string str;
	cin >> str;
	for(int i=0; i<str.size(); i++){
		arr[str[i]-'a']++;
	}
	for(int i=0; i<26; i++){
		if(arr[i] > maxim){
			ch = i + 'a';
			maxim = max(arr[i], maxim);
		}
	}
	cout << ch << endl;
	return 0;
}
