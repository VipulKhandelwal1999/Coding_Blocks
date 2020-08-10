/*
Given an n x m matrix, where every row and column is sorted in increasing order, and a number x . Find if element x is present in the matrix or not.

Input Format
First line consists of two space separated integers N and M, denoting the number of element in a row and column respectively. Second line of each test case consists of N*M space separated integers denoting the elements in the matrix in row major order. Third line of each test case contains a single integer x, the element to be searched.

Constraints
1 <= N,M <= 30 0 <= A[i] <= 100

Output Format
Print 1 if the element is present in the matrix, else 0.

Sample Input
3 3
3 30 38
44 52 54
57 60 69
62
Sample Output
0
Explanation
Search the element in the sorted matrix. If the element is present print 1 otherwise print 0. In the sample input,in first case 62 is not present in the matrix so 0 is printed. Similarly, for second case 55 is present in the matrix so 1 is printed.

Logic:-
There are three approaches to do this problem.

1.By doing linear search in every row of the matrix.

2.By doing binary search in every row of the matrix.

3.Optimized approach
Time complexity: O(n+m) where n is number of rows and m is number of columns.

Algo: We will make use of the fact that matrix is row wise and column wise sorted. So if we start from the top right we can observe the fact that if we go in the left direction the numbers decrease and if we go downwards the numbers increase. So we can restrict our search space depending on which index we are currently at. If the number at which we are currently standing is greater than the target number then it is obvious that we can find it on the left side of the current row and if the target is greater than the element at current standing then it is obvious that we can find it towards the bottom in that column where every number is greater.

1.Let array be arr and target be the element to be found.
2.Iterate over each row

      2.1  Iterate over each column in reverse order
            2.1.1 If arr[row][col]==target then break the loop and print 1
            2.1.2 if arr[row][col]>target then
                         col--;            //decrement  columns
            2.1.3 else  row++;    //increment rows
3.If loop is not broken in between then it indicates that element is not present in arr .So print 0.
*/


#include <iostream>
using namespace std;

void matrixSearch(int **arr, int n , int m, int key) {
    for(int row = 0;row < n;) {
        for(int col=m-1;col>=0 and row < n;) {
            if(arr[row][col] == key) {
                cout<<1;
                return;
            } else if(arr[row][col] > key) {
                col--;
            } else {
                row++;
            }
        }
    }
    cout<<0;
    return ;
}

int main() {
    int n, m;
    cin>>n>>m;
    int **arr = new int*[n];
    for(int i=0;i<n;i++) {
        arr[i]=new int[m];
    }
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cin>>arr[i][j];
        }
    }
    int key;
    cin>>key;
    matrixSearch(arr, n, m, key);
}
