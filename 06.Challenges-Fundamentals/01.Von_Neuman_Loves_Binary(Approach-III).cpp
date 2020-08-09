/*
Given a binary number ,help Von Neuman to find out its decimal representation. For eg 000111 in binary is 7 in decimal.

Input Format
The first line contains N , the number of binary numbers. Next N lines contain N integers each representing binary represenation of number.

Constraints
N<=1000 Digits in binary representation is <=16.

Output Format
N lines,each containing a decimal equivalent of the binary number.

Sample Input
4
101
1111
00110
111111
Sample Output
5
15
6
63
Explanation
For binary number fedcba , Decimal number = f * 25 + e * 24 + d * 23 + …..+ a * 20.

Logic:-
For binary number fedcba , Decimal number = f.2^5 + e.2^4 + d.2^3 + …..+ a.2^0.

The idea is to extract the digits of given binary number starting from right most digit and keep a variable decvalue.
At the time of extracting digits from the binary number, multiply the digit with the proper base (Power of 2)
and add it to the variable dec_value.
At the end, the variable decvalue will store the required decimal number.
*/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int binaryToDecimal(int n){
    int num = n;
    int dec_value = 0;

    // Initializing base
    // value to 1, i.e 2^0
    int base = 1;

    int temp = num;
    while (temp > 0)
    {
        int last_digit = temp % 10;  // Extract rightmost digit
        temp = temp / 10;               // Update the number

        dec_value += last_digit * base;  // Add the digit to the answer

        base = base * 2;               //Update the power of 2
    }

    return dec_value;                 // Return ans
}

int main() {
	int n;
	cin >> n;
	while(n--){
        int x;
		cin >> x;
		cout << binaryToDecimal(x) << endl;
	}
	return 0;
}
