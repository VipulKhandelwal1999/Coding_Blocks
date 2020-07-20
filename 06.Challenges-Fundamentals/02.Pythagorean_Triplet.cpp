/*Hacker Blocks*/
/*Title - Pythagorean Triplet*/
/*Given a number N (denoting one of the legs of the triangle), Print its Pythagoras pair in increasing order if they exist. Otherwise, print "-1".

Input Format
A single integer N

Constraints
N <= 10^9

Output Format
Two numbers X and Y denoting the rest of the numbers of the Pythagorean triplet in increasing order.

Sample Input
3
Sample Output
4 5
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main() {
	long long n;
	cin >> n;

	if (n == 1 || n == 2)
        cout << "-1" << endl;

    else if (n % 2 == 0) {
        long long var =  n * n / 4;
		cout << var - 1 << " " << var + 1;
    }

    else if (n % 2 != 0) {
        long long var =  n * n + 1;
		cout << var/2 -1 << " " << var/2;
    }
	return 0;
}
