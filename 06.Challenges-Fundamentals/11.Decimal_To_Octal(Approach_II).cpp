/*
Take N (number in decimal format). Write a function that converts it to octal format. Print the value returned.

Input Format
Constraints
0 < N <= 1000000000

Output Format
Sample Input
63
Sample Output
77
Explanation
Both input and output are integers

Logic:-
Required Code for decimal to octal is given below :

Algorithm:

Store the remainder when the number is divided by 8 in an array.
Divide the number by 8 now
Repeat the above two steps until the number is not equal to 0.
Print the array in reverse order now.
Figure

For Example:

If the given decimal number is 16.
Step 1: Remainder when 16 is divided by 8 is 0. Therefore, arr[0] = 0.
Step 2: Divide 16 by 8. New number is 16/8 = 2.
Step 3: Remainder when 2 is divided by 8 is 2. Therefore, arr[1] = 2.
Step 4: Divide 2 by 8. New number is 2/8 = 0.
Step 5: Since number becomes = 0. Stop repeating steps and print the array in reverse order. Therefore the equivalent octal number is 20.
*/
#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;

    string octal = "";
    while(n!=0){
        int r = n%8;
        n/=8;
        char c = r+'0';
        octal = c+octal;
    }
    cout << octal <<endl;
}
