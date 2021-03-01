/*
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

Logic:-
You can solve this problem in O(n) time using the two pointer approach.

Make two variabes , say i and j .
i defines the beginning of a window and j defines its end.
Start i from 0 and j from k.
Let’s talk about the singular case when we are considering the max window for only 'a’s and consider only the swapping of b-> a. If we are able to get the answer for max window of consecutive 'a’s , we can simply implement the same algo for the max ‘b’ window as well.
So we started i from 0 and j from k.
Move j ahead freely as long as there are ‘a’ characters at s[ j ] position.
Maintain a count variable which counts the number of swaps made or the number of 'b’s in our A window.
If you encounter a ‘b’ char at s[ j ] position , increment the count variable. Count should never exceed k .
Take the size of the window at every point using length = j - i + 1;
Compute the max size window this way and do the same for ‘b’ as well.
Output the maximum size window of ‘a’ and ‘b’.
*/

#include<bits/stdc++.h>
using namespace std;

int main() {
	
	int k;
    cin >> k;
    string s;
    cin >> s;
    int n=s.length();
    int ind1=0;
    int ans=1;
    int ca=0,cb=0;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='a')
            ca++;
        else
            cb++;
        while(min(ca,cb)>k)
        {
            if(s[ind1]=='a')
            {
                ca--;
            }
            else
            {
                cb--;
            }
            ind1++;
        }
        ans=max(ans,i-ind1+1);
    }
    cout << ans << endl;
	
	return 0;
}