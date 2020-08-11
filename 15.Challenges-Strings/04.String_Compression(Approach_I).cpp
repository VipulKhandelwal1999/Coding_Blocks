/*
Take as input S, a string. Write a function that does basic string compression. Print the value returned. E.g. for input “aaabbccds” print out a3b2c2d1s1.

Input Format
A single String S

Constraints
1 < = length of String < = 1000

Output Format
The compressed String.

Sample Input
aaabbccds
Sample Output
a3b2c2d1s1
Explanation
In the given sample test case 'a' is repeated 3 times consecutively, 'b' is repeated twice, 'c' is repeated twice and 'd and 's' occurred only once.

Logic:-
Take the first character of the present string and store it in say 'ch'. Start iterating over the string and obtain the count of this character occurring consecutively from this point.
Obtain the answer for remaining string recursively.
Return ch+countOfCh+recursiveResult .
*/

#include <bits/stdc++.h>
using namespace std;

string compress(string s)
{
    if (s.size() == 0)
    {
        return "";
    }

    char ch = s[0];
    int i = 1;
    while (i < s.size() && s[i] == ch)
    {
        i++;
    }

    string ros = s.substr(i);
    ros = compress(ros);

    string charCount = to_string(i);
    return ch + charCount + ros;
}
