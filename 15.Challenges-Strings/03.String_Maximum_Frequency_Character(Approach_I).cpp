/*
Take as input S, a string. Write a function that returns the character with maximum frequency. Print the value returned.

Input Format
String

Constraints
A string of length between 1 to 1000.

Output Format
Character

Sample Input
aaabacb
Sample Output
a
Explanation
For the given input string, a appear 4 times. Hence, it is the most frequent character.

Logic:-
1.Declare an Array of 26 size to store the Freq of each character.
2.Each time any character is encountered increment its corresponding freq at that index. 3.Declare a max variable and put a loop on filled array. 4.Update the max and character accordingly.
*/


#include <iostream>
using namespace std;
int main() {
    char str[1000];
    int freq[256];
    cin>>str;

    for(int x=0;str[x]!='\0';x++){
        freq[str[x]]++;
    }
    int ans=0;
    char ch;
    for(int x=0;x<256;x++){
        if(freq[x]>0){
            if(freq[x]>ans){
                ans=freq[x];
                ch=char(x);
            }
        }
    }
    cout<<ch;
}
