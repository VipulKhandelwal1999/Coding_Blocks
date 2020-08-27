/*
Take as input x and n, two numbers. Write a function to calculate x raise to power n. Target complexity is O(logn). NOTE: Try both recursive and bitmasking approach.

Input Format
Enter the number N and its power P

Constraints
None

Output Format
Display N^P

Sample Input
2
3
Sample Output
8

Logic:-
Using divide and conquer technique we can observe the following recurrence
power(x, n) = power(x, n / 2) * power(x, n / 2); // else n is even
power(x, n) = x * power(x, n / 2) * power(x, n / 2); // if n is odd

*/
#include<iostream>
using namespace std;

float power(float x, int y)
{
    float temp;
    if( y == 0)
       return 1;
    temp = power(x, y/2);
    if (y%2 == 0)
        return temp*temp;
    else
    {
        if(y > 0)
            return x*temp*temp;
        else
            return (temp*temp)/x;
    }
}

int main() {
    int num,pw;
    cin>>num>>pw;
    cout<<power(num,pw);
    return 0;
}
