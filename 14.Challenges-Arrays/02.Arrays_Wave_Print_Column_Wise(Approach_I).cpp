/*
Take as input a two-d array. Wave print it column-wise.

Input Format
Two integers M(row) and N(colomn) and further M * N integers(2-d array numbers).

Constraints
Both M and N are between 1 to 10.

Output Format
All M * N integers seperated by commas with 'END' wriiten in the end(as shown in example).

Sample Input
4 4
11 12 13 14
21 22 23 24
31 32 33 34
41 42 43 44
Sample Output
11, 21, 31, 41, 42, 32, 22, 12, 13, 23, 33, 43, 44, 34, 24, 14, END

Logic:-
For the case:

4 5

1 2 3 4 5

6 7 8 9 10

11 12 13 14 15

16 17 18 19 10

In wave print column wise, for each column we need to print elements of each row starting from 0th(min) row to 4th(max) row and from 4th (max) row to 0th(min) row alternatively.



Thus, output is 1, 6, 11, 16, 17, 12, 7, 2, 3, 8, 13, 18, 19, 14, 9, 4, 5, 10, 15, 10, END
*/
#include <iostream>
using namespace std;
int main() {
    int nRow,nCol;
    cin >> nRow >> nCol;

    int a[nRow][nCol];

//Take Input
    for (int i = 0; i < nRow; i++) {
        for (int j = 0; j < nCol; j++) {
            cin >> a[i][j];
        }
    }
    //Iterating over each column
    for (int j = 0; j < nCol; j++) {

//for odd columns printing elements of rows from max row to min row
//for even columns printing elements of rows from min row to max row
//Thus forming a wave pattern.
        if( j%2!=0){
            //for odd column
            for (int i = nRow-1; i >= 0; i--) {
                cout << a[i][j] << ", ";
            }
        }else{
            //for even column
            for (int i = 0; i < nRow; i++) {
                cout << a[i][j] << ", ";
            }
        }
    }
    cout << "END" <<endl;
}
