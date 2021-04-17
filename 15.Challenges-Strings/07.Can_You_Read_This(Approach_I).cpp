/*
One of the important aspect of object oriented programming is readability of the code. To enhance the readability of code, developers write function and variable names in Camel Case. You are given a string, S, written in Camel Case. FindAllTheWordsContainedInIt.

Input Format
A single line contains the string.

Constraints
|S|<=1000

Output Format
Print words present in the string, in the order in which it appears in the string.

Sample Input
IAmACompetitiveProgrammer
Sample Output
I
Am
A
Competitive
Programmer
Explanation
There are 5 words in the string.

Logic:-
Problem can be solved by dividing the input string at position, i, either if  is the last letter, or  is a capital letter.
*/

#include "bits/stdc++.h"
#define mod 1000000007
#define nn 100010

using namespace std;

int main()
{
    int n;
    string s;
    cin>>s;
    n=s.length();
    string pr;
    for(int i=0;i<n;i++)
    {
        pr.push_back(s[i]);
        if(i==n-1) //last letter
            cout<<pr<<endl;
        else if(s[i+1]>='A' && s[i+1]<='Z') //s[i+1] is a capital letter.
        {
            cout<<pr<<endl;
            pr.clear();
        }
    }
    return 0;
}
