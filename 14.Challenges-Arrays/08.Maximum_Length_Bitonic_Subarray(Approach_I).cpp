/*
You are provided n numbers of array. You need to find the maximum length of bitonic subarray. A subarray A[i � j] is biotonic if there is a k with i <= k <= j such that A[i] <= A[i + 1] � <= A[k] >= A[k + 1] >= .. A[j � 1] > = A[j] i.e subarray is first increasing and then decreasing or entirely increasing or decreasing.

Input Format
First line contains integer t which is number of test case. For each test case, it contains an integer n which is the size of array and next line contains n space separated integers.

Constraints
1<=t<=100 1<=n<=1000000

Output Format
Print the maximum length.

Sample Input
2
6
12 4 78 90 45 23
4
40 30 20 10
Sample Output
5
4
Explanation
ForMaximum length = 4, 78, 90, 45, 23

Logic:-
We create two arrays - 'inc' and 'dec'

inc[i] stores the length of increasing subarray till i.
dec[i] stores the length of decreasing subarray starting from index i.
Doing so gives us the length of increasing and decreasing subarray at each index in O(n) time.
We calculate the length of the longest bitonic subarray by finding the maximum inc[i] + dec[i] - 1
We subtract one since the current element at ith index is included in both the increasing and decreasing subarray lengths.
Algorithm
Initialize inc[0] to 1 and dec[n-1] to 1

Creating inc[] array
a. Till end of the array ie, i=1 to n, if arr[i] > arr[i-1] then inc[i] = inc[i-1] + 1. else, inc[i] = 1

Creating dec[] array
a. From the end of the array ie, i = n-2 till i =0, if arr[i] > arr[i+1] then dec[i] = dec[i+1] +1 else, dec[i] = 1
*/

int bitonic(int arr[], int n)
{
    int inc[n]; // Length of increasing subarray ending at all indexes
    int dec[n]; // Length of decreasing subarray starting at all indexes
    int i, max;

    // length of increasing sequence ending at first index is 1
    inc[0] = 1;

    // length of increasing sequence starting at first index is 1
    dec[n-1] = 1;

    // Step 1) Construct increasing sequence array
    for (i = 1; i < n; i++)
    inc[i] = (arr[i] >= arr[i-1])? inc[i-1] + 1: 1;

    // Step 2) Construct decreasing sequence array
    for (i = n-2; i >= 0; i--)
    dec[i] = (arr[i] >= arr[i+1])? dec[i+1] + 1: 1;

    // Step 3) Find the length of maximum length bitonic sequence
    max = inc[0] + dec[0] - 1;
    for (i = 1; i < n; i++)
        if (inc[i] + dec[i] - 1 > max)
            max = inc[i] + dec[i] - 1;

    return max;
}
