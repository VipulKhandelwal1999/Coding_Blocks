/*
Prateek Bhayia likes to play with bits. One day Prateek bhayia decides to assign a task to his student Sanya. You have help Sanya to complete this task. Task is as follows - Prateek Bhayia gives Q queries each query containing two integers a and b. Your task is to count the no of set-bits in for all numbers between a and b (both inclusive)

Input Format
Read Q - No of Queries, Followed by Q lines containing 2 integers a and b.

Constraints
Q,a,b are integers.

Output Format
Q lines, each containing an output for your query.

Sample Input
2
1 1
10 15
Sample Output
1
17

Logic:-
This is a quite simple problem to tackle. Just loop through all the numbers between a and b and calculate the no of set bits using either brian kernighan algo or the inbuilt function for counting set bits
*/

#include<bits/stdc++.h>
using namespace std;

int main() {

	int q;
	cin >> q;
	while(q--){
		int a, b;
		cin >> a >> b;
		int sum = 0;
		for(int i=a; i<=b; i++){
			sum += __builtin_popcount(i);
		}
		cout << sum << endl;
	}

	return 0;
}
