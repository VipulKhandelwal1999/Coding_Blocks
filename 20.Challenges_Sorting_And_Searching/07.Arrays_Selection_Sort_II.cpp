/*
Take as input N, the size of array. Take N more inputs and store that in an array. Write a function that selection sorts the array. Print the elements of sorted array.

1.It reads a number N.
2.Take Another N numbers as input and store them in an Array.
3.Sort the array using Selection Sort and print that Array.

Input Format
Constraints
N cannot be Negative. Range of Numbers can be between -1000000000 to 1000000000.

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
Write selection sort to sort the given integers in the problem.

Logic:-
The selection sort algorithm sorts an array by repeatedly finding the minimum element (considering ascending order) from unsorted part and putting it at the beginning.The algorithm maintains two subarrays in a given array.

1) The subarray which is already sorted.
2) Remaining subarray which is unsorted.

In every iteration of selection sort, the minimum element (considering ascending order) from the unsorted subarray is picked and moved to the sorted subarray. For example , array={20,12,10,15,2}

After step 4, array is sorted. So output is 2 10 12 15 20.
*/

#include <iostream>
using namespace std;
int main() {
    long long int n;
    cin >> n;
    long long int i,j, t;
    long long int arr[n];

    //Input from user
    for (i = 0; i < n; i++)
        cin >> arr[i];

    //Selection sort for sorting the element of given array
    for (i = 0; i < n; i++)
    {
        //Comparision for sorting the element of given array.
        for ( j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[i])
                {
                     int u = arr[i];
                     arr[i] = arr[j];
                     arr[j] = u;
                }
        }

    }
  //display sorted array
    for (i = 0; i < n; i++)
        cout << arr[i] << endl;

    return 0;
}
