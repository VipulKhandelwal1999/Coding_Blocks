/*
Take as input x and n, two numbers. Write a function to calculate x raise to power n. Target complexity is O(logn). NOTE: Try both recursive and bitmasking approach.

Input Format
Enter the number N and its power P

Constraints
None

Output Format
Display N^P

Sample Input
2
3
Sample Output
8
*/

#include<iostream>
using namespace std;


//Exponentiation/Power using Bitmasking
int power_optimised(int a, int n) {
	int ans = 1;

	while (n > 0) {
		int last_bit = (n & 1);
		if (last_bit) {
			ans = ans * a;
		}
		a = a * a; //Square up
		n = n >> 1; //Discard the last bit of N
	}
	return ans;

	return 0;
}


int main() {

	int a, n;
	cin >> a >> n;

	cout << power_optimised(a, n) << endl;


	return 0;
}
