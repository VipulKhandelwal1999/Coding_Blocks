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
using namespace std;

int main() {

	int n;
	int a[100005];
	cin >> n;

	int no;
	int res = 0;


	for (int i = 0; i < n; i++) {
		cin >> no;
		a[i] = no;
		res = res ^ no;
	}
	// xor = a^b;
	int temp = res;
	int pos = 0;
	while ((temp & 1) != 1) {
		pos++;
		temp = temp >> 1;
	}

	//The first bit in xor is at position 'pos'
	int mask = (1 << pos);

	//find those numbers which contain set bit at position pos
	int x = 0;
	int y = 0;

	for (int i = 0; i < n; i++) {
		if ((a[i]&mask) > 0) {
			x = x ^ a[i];
		}
	}
	y = res ^ x;

	cout << min(x, y) << " " << max(x, y) << endl;
	return 0;
}
