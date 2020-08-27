/*
Take as input N, the size of array. Take N more inputs and store that in an array. Write a function that bubble sorts the array. Print the elements of sorted array.

1.It reads a number N.
2.Take Another N numbers as input and store them in an Array.
3.Bubble sort the array and print the Array.

Input Format
Constraints
N cannot be Negative. Range of Numbers can be between -1000000000 to 100000000.

Output Format
Sample Input
4
2
-18
45
30
Sample Output
-18
2
30
45
Explanation
For each test case write bubble sorting program to sort the elements of the array.

Logic:-
Bubble sort is comparison-based algorithm in which each pair of adjacent elements is compared and the elements are swapped if they are not in order. For example array={-2,45,0,11,-9}


The sorted array after 4th step is -9 -2 0 11 45.
*/
#include <iostream>
using namespace std;
int main() {
    long long int n;
    cin >> n;
    long long int i,j,k;
    long long int arr[n];

    //Input from the user
    for (i = 0; i < n; i++)
        cin >> arr[i];

    //Two for loof which compare the element of arrays.
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n-1;j++)
        {
            if (arr[j] > arr[j+1])
            {
                k = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = k;
            }
        }
    }

    //Print required Output
    for (i = 0; i < n; i++)
        cout << arr[i] << endl;

    return 0;
}
