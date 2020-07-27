/*
Print "lowercase" if user enters a character between 'a-z' , Print "UPPERCASE" is character lies between 'A-Z' and print "Invalid" for all other characters like $,.^# etc.

Input Format
Single Character .

Constraints
-

Output Format
lowercase UPPERCASE Invalid

Sample Input
$
Sample Output
Invalid
Explanation
-
*/

#include<bits/stdc++.h>
using namespace std;
int main() {
	char ch;
	cin >> ch;
	if(ch>='A' && ch<='Z')
		cout << "UPPERCASE";
	else if(ch>='a' && ch<='z')
		cout << "lowercase";
	else{
		cout << "Invalid";
	}
	return 0;
}
