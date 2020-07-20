/*
Given number of rows N, you have to print a Hollow Rhombus. See the output for corresponding given input.

Input Format
Single integer N.

Constraints
N <= 20

Output Format
Print pattern.

Sample Input
5
Sample Output
    *****
   *   *
  *   *
 *   *
*****
Explanation
For any input N. First line contains 4 space and then 5 {*} and then the second line contains according to the output format.
*/

#include<iostream>
using namespace std;
void hollowRhombus(int rows)
{
    int i, j;
    for (i=1; i<=rows; i++)
    {
        for (j=1; j<=rows - i; j++)
            cout << " ";
        if (i==1 || i==rows)
            for (j=1; j<=rows; j++)
                cout << "*";
        else
            for (j=1; j<=rows; j++)
                if (j==1 || j==rows)
                    cout << "*";
                else
                    cout << " ";
        cout << "\n";
    }
}
int main() {
	int n;
	cin >> n;
	hollowRhombus(n);
	return 0;
}
