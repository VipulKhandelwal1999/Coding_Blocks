/*
We are given two coins of value x and y. We have to find the maximum of value of a XOR b where x <= a <= b <= y.

Input Format
We are given two integers x and y

Constraints
l <= r <= 1000

Output Format
Print the maximum value of a XOR b

Sample Input
5
6
Sample Output
3
Explanation
If a and b are taken to be 5. Then a xor b = 0
If a and b are taken to be 6. Then a xor b = 0
If a is 5 and b is 6. Then a xor b is 3.
*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll pow(ll x, ll y)
{
    ll temp;
    if(y == 0)
        return 1;
    temp = pow(x, y/2);
    if (y%2 == 0)
        return temp*temp;
    else
        return x*temp*temp;
}

int main () {

	ll x, y;
	cin >> x >> y;
	ll range = x^y;
    int msbPos = 0;
    while (range)
    {
        msbPos++;
        range >>= 1;
    }
	cout << pow(2, msbPos)-1 << endl;

	return 0;
}
