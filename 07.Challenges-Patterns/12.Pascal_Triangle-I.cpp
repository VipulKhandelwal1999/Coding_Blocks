/*
Given an integer N, print Pascal Triangle upto N rows.

Input Format
Single integer N.

Constraints
N <= 10

Output Format
Print pascal triangle.

Sample Input
4
Sample Output
           1
         1   1
       1   2   1
     1   3   3   1
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int rows, coef = 1;
    cin >> rows;

    for(int i = 0; i < rows; i++)
    {
        for(int space = 1; space <= rows-i; space++)
            cout <<"  ";

        for(int j = 0; j <= i; j++)
        {
            if (j == 0 || i == 0)
                coef = 1;
            else
                coef = coef*(i-j+1)/j;

            cout << coef << "   ";
        }
        cout << endl;
    }

    return 0;
}
