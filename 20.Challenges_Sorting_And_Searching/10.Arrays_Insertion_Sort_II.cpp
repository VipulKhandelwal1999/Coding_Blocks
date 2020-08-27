/*
Given an array A of size N , write a function that implements insertion sort on the array. Print the elements of sorted array.

Input Format
First line contains a single integer N denoting the size of the array. Next line contains N space seperated integers where ith integer is the ith element of the array.

Constraints
1 <= N <= 1000
|Ai| <= 1000000

Output Format
Output N space seperated integers of the sorted array in a single line.

Sample Input
4
3 4 2 1
Sample Output
1 2 3 4
Explanation
For each test case, write insertion sort to sort the array.

Logic:-
nsertion sort is a simple sorting algorithm that builds the final sorted array one item at a time.
Algorithm:
Step 1 − First element is already sorted.
Step 2 − Pick next element
Step 3 − Compare with all elements in the sorted sub-list
Step 4 − Shift all the elements in the sorted sub-list that is greater than the value to be sorted
Step 5 − Insert the value
Step 6 − Repeat steps 2,3,4,5 until list is sorted
*/

#include <stdio.h>
#include <math.h>
#include <iostream>
using namespace std;
/* Function to sort an array using insertion sort*/
void insertionSort(long long int arr[], long long int n)
{
int i, key, j;
for (i = 1; i < n; i++)
{
    key = arr[i];
    j = i-1;

    /* Move elements of arr[0..i-1], that are
        greater than key, to one position ahead
        of their current position */
    while (j >= 0 && arr[j] > key)
    {
        arr[j+1] = arr[j];
        j = j-1;
    }
    arr[j+1] = key;
}
}

// A utility function to print an array of size n
void printArray(long long int arr[],long long int n)
{
int i;
for (i=0; i < n; i++)
    printf("%d ", arr[i]);
printf("\n");
}



/* Driver program to test insertion sort */
int main()
{

    long long int n;
    cin>>n;
    long long int arr[n];
    for (int i = 0; i < n; i++)
        cin>>arr[i];

    insertionSort(arr, n);
    printArray(arr, n);

    return 0;
}
