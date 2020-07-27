/*
Problem Statement:
    Sanket has a string consisting of only 'a' and 'b' as the characters. Sanket describes perfectness of a string as the maximum length substring of equal characters. Sanket is given a number k which denotes the maximum number of characters he can change. Find the maximum perfectness he can generate by changing no more than k characters.

    Input Format
    The first line contains an integer denoting the value of K. The next line contains a string having only ‘a’ and ‘b’ as the characters.

    Constraints
    2 ≤ N ≤ 10^6

    Output Format
    A single integer denoting the maximum perfectness achievable.

    Sample Input
    2
    abba
    Sample Output
    4
    Explanation
    We can swap the a's to b using the 2 swaps and obtain the string "bbbb". This would have all the b's and hence the answer 4.
    Alternatively, we can also swap the b's to make "aaaa". The final answer remains the same for both cases.

    Sanket has a string consisting of only a and b as the characters.
    Sanket describes perfectness of a string as the maximum length
    substring of equal characters. Sanket is given a number K which denotes
    the maximum number of characters he can change. Find the maximum perfectness
    he can generate by changing no more than k characters


    Input Format:
    The first line contains an integer denoting the value of K. The next line contains a string having on ‘a’ and ‘b’ as the characters

    Constraints:
    2 ≤ N ≤ 10^5

    Output Format:
    Single integer denoting the maximum perfectness achievable

    Sample Input:
    2
    abba
    Sample Output:
    4


dry run starts:
    for a given senario length of string is 4
    so loop run for times

    take a frequency array of size 2 because its given that input can only have a and b
    initially array is like
    a   b
    0   0
    when i=0
    char temp =a
    at line no 25
    freq[temp-'a']++;
    ascii value of a =97
    freq['a'-'a']++;
    so freq[0]++;
    frequency of a is incremented
    a  b
    1  0
    here line no 26 we are check maximum perfectness he can generate by changing no more than k characters
    so min(0,1)>2;
    line no 26 will not execute
    ans++;
    so ans=1;
    when i=1;
    char temp=b;
    at line no 25
    freq[temp-'a']++;
    freq['b'-a]++;
    ascii of b is 98
    so freq[98-97]++;
    freq[1]++;
    now frequency is become
    a   b
    1   1
    but again line no 26 will not execute because
    min(1,1)>2
    but ans will updated
    ans++;
    ans=2;
    when i=2
    char temp =b;
    at line no 25
    freq[temp-'a']++;
    freq['b'-'a']++;
    again
    freq[1]++;
    so frequency of a and b become
    a   b
    1   2
    line no 26 will not execute because
    min(1,2)>2
    but ans++;
    ans=3;
    when i=3
    char temp=a;
    freq['a'-'a']++;
    freq[0]++;
    so frequency of a and b
    a   b
    2   2
    but still line no 26 will not execute
    min(2,2)>2
    so ans will update again
    ans++;
    ans=4;
    final ans will 4
*/

#include<bits/stdc++.h>
using namespace std;

#define ll long long int

int main()
{

    int k;
    cin >> k;
    string str;
    cin >> str;
    int freq[2] = {0};
    ll n = str.length();
    ll ans = 0, left = 0;
    for (ll i = 0; i < n; i++)
    {
        char temp = str[i];
        freq[temp - 'a']++;
        if (min(freq[0], freq[1]) > k)
        {
            freq[str[left] - 'a']--;
            left++;
        }
        else
            ans++;
    }
    cout << ans << endl;
    return 0;
}
