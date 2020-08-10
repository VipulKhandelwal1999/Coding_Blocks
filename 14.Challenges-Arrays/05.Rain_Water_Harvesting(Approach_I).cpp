/*
Apoorvaa has created an elevated roof. She wants to know how much water can she save during rain.

Given n non negative integers representing the elevation map where width of every bar is 1, Find the maximum water that she can save.

Explanation for the Sample input Testcase:
Elevation Map

So the total units of water she can save is 5 units

Input Format
First line contains an integer n. Second line contains n space separated integers representing the elevation map.

Constraints
1 <= N <= 10^6

Output Format
Print a single integer containing the maximum unit of waters she can save.

Sample Input
10
0 2 1 3 0 1 2 1 2 1
Sample Output
5
Explanation
Refer to the image for explanation. Count the number of cells having water in them.

Logic:-
An element of the array can store water if there are higher bars on left and right. We can find the amount of water to be stored in every element by finding the heights of bars on left and right sides. The idea is to compute the amount of water that can be stored in every element of array. For example, consider the array {3, 0, 0, 2, 0, 4}, we can store three units of water at indexes 1 and 2, and one unit of water at index 3, and three units of water at index 4.

A Simple Solution is to traverse every array element and find the highest bars on left and right sides. Take the smaller of two heights. The difference between the smaller height and height of the current element is the amount of water that can be stored in this array element. Time complexity of this solution is O(n2).
*/

int maxWater(int arr[], int n)
{

// To store the maximum water
// that can be stored
int res = 0;

// For every element of the array
for (int i = 1; i < n-1; i++) {

    // Find the maximum element on its left
    int left = arr[i];
    for (int j=0; j<i; j++)
       left = max(left, arr[j]);

    // Find the maximum element on its right
    int right = arr[i];
    for (int j=i+1; j<n; j++)
       right = max(right, arr[j]);

   // Update the maximum water
   res = res + (min(left, right) - arr[i]);
}

return res;
}
