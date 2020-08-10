/*
Given a 2D array of size N x N. Rotate the array 90 degrees anti-clockwise.



Input Format
First line contains a single integer N. Next N lines contain N space separated integers.

Constraints
N < 1000

Output Format
Print N lines with N space separated integers of the rotated array.

Sample Input
4
1 2 3 4
5 6 7 8
9 10 11 12
13 14 15 16
Sample Output
4 8 12 16
3 7 11 15
2 6 10 14
1 5 9 13
Explanation
Rotate the array 90 degrees anticlockwise.

Logic:-
A simple trick that we can observe is that we can first transpose the whole matrix along the leading diagonal and then reverse each row of the matrix. The resulting matrix will be out the rotated matrix. Here is the code for the following algorithm.
*/

#include <iostream>
using namespace std;
int main(int argc, char* argv[])
{
    int n,m;
    std::cin >> n;
    m=n;
    int array[n][m];
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cin>>array[i][j];
        }
    }

    for(int i=0;i<n;i++) {
        for(int j=i;j<m;j++) {
            swap(array[i][j],array[j][i]);
        }
    }

    for(int i=0;i<n;i++) {
        int lo = 0;
        int hi = n-1;
        while(lo<=hi) {
            swap(array[lo][i], array[hi][i]);
            lo++;
            hi--;
        }
    }

    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cout<<array[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}
