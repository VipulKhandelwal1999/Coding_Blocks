/*
Take as input N, an odd number (>=5) . Print the following pattern as given below for N = 7.

*  ****
*  *
*  *
*******
   *  *
   *  *
****  *
Input Format
Enter value of N ( >=5 )

Constraints
5 <= N <= 99

Output Format
Print the required pattern.

Sample Input
7
Sample Output
*  ****
*  *
*  *
*******
   *  *
   *  *
****  *
Explanation
Catch the pattern for the corresponding input and print it accordingly.
*/

#include <bits/stdc++.h>
using namespace std;

void swastika(int row, int col)
{
for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {

    // checking if i < row/2
    if (i < row / 2) {

        // checking if j<col/2
        if (j < col / 2) {

        // print '*' if j=0
        if (j == 0)
            cout << "*";

        // else print space
        else
            cout << " ";
        }

        // check if j=col/2
        else if (j == col / 2)
        cout << "*";
        else
        {
        // if i=0 then first row will have '*'
        if (i == 0)
            cout << "*";
        }
    }
    else if (i == row / 2)
        cout << "*";
    else {

        // middle column and last column will have '*'
        // after i > row/2
        if (j == col / 2 || j == col - 1)
        cout << "*";

        // last row
        else if (i == row - 1) {

        // last row will be have '*' if
        // j <= col/2 or if it is last column
        if (j <= col / 2 || j == col - 1)
            cout << "*";
        else
            cout << " ";
        }
        else
        cout << " ";
    }
    }
    cout << "\n";
}
}

// driver code
int main()
{
	int n;
	cin >> n;
   	swastika(n, n);

   return 0;
}
