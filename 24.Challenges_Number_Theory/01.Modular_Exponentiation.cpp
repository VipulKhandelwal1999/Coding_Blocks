/*
Given three numbers a,b,c. Calculate (a^b)mod c.

Input Format
Single line containing three integers a,b,c separated by space.

Constraints
1<=a,b,c<=100000

Output Format
Print (a^b)mod c.

Sample Input
2 2 3
Sample Output
1
Explanation
(2^2)mod 3=4 mod 3 = 1
*/

#include<bits/stdc++.h>
using namespace std;

#define ll long long

ll power(ll a, ll n, ll m){
	if(n==0)
		return 1;
	else if (n % 2 == 0)
        return (power(a, n / 2, m) * power(a, n / 2, m))% m;
    else
        return (a * power(a, n / 2, m) * power(a, n / 2, m)) % m;

}

int main() {
	ll a, b, c;
	cin >> a >> b >> c;
	cout << power(a,b,c) << endl;
	return 0;
}
