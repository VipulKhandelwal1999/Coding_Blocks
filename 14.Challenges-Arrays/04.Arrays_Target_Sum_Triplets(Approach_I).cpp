/*
Take as input N, the size of array. Take N more inputs and store that in an array. Take as input “target”, a number. Write a function which prints all triplets of numbers which sum to target.

Input Format
First line contains input N.
Next line contains N space separated integers denoting the elements of the array.
The third line contains a single integer T denoting the target element.

Constraints
Length of Array should be between 1 and 1000.

Output Format
Print all the triplet present in the array in a new line each. The triplets must be printed as A, B and C where A,B and C are the elements of the triplet ( A<=B<=C) and all triplets must be printed in sorted order. Print only unique triplets.

Sample Input
9
5 7 9 1 2 4 6 8 3
10
Sample Output
1, 2 and 7
1, 3 and 6
1, 4 and 5
2, 3 and 5
Explanation
Array = {5, 7, 9, 1, 2, 4, 6 ,8 ,3}. Target number = 10. Find any three number in the given array which sum to target number.

Logic:-
For the sample case, Array = {5, 7, 9, 1, 2, 4, 6 ,8 ,3}. Target number = 10.
Find any three numbers in the given array whose sum is equal to the target number. In this case triplets are:

1, 2 and 7

1, 3 and 6

1, 4 and 5

2, 3 and 5

Algorithm:

1.Sort the element in ascending order

Start a loop from i=0 to i<n. We mark arr[i] at each instance as a fixed element for that iteration and work to find a pair of elements such that their sum is equal to target-arr[i] hence ensuring that the net sum of the three elements would be equal to target.

Inside this loop, implement the two pointer approach. Keep a left pointer starting from i+1 and a right pointer from n-1.

Work an inner left till left<right. For each iteration , check whether a[i] + a[left] + a[right] == target. If so ,print the triplet. Else if this sum = a[i] + a[left] + a[right] is less than the target , then increment the left pointer by one. Else decrement the right pointer by one.

3.Thus, all the triplets have been printed.
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[1005];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int target;
    cin >> target;

    sort(a, a + n);


    for (int i = 0; i < n; i++)
    {
        int l = i + 1;
        int r = n - 1;
        while (l < r)
        {
            if (a[i] + a[l] + a[r] == target)
            {
                cout << a[i] << ", " << a[l] << " and " << a[r] << endl;
                l++;
                r--;
            }
            else if (a[i] + a[l] + a[r] < target)
                l++;
            else
                r--;
        }
    }

    return 0;
}
