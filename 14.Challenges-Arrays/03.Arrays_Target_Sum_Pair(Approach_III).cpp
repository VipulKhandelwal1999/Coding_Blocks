/*
Take as input N, the size of array. Take N more inputs and store that in an array. Take as input “target”, a number. Write a function which prints all pairs of numbers which sum to target.

Input Format
The first line contains input N. Next N lines contains the elements of array and (N+1)th line contains target number.

Constraints
Length of the arrays should be between 1 and 1000.

Output Format
Print all the pairs of numbers which sum to target. Print each pair in increasing order.

Sample Input
5
1
3
4
2
5
5
Sample Output
1 and 4
2 and 3
Explanation
Find any pair of elements in the array which has sum equal to target element and print them.

Logic:-
For the sample case, array = [1,3,4,2,5] and target=5, we need to find two numbers whose sum is equal to the target.Here in this case target sum pairs are 1, 4 and 2 , 3.

Algorithm:

1.First sort the given array.
2.Now take two variables one as left and other as right starting from 0th and end index of the sorted array respectively.
3.Now iterate till left<right.

        3.1 Calculate the sum of the elements at left and right position
        3.1.1 If the sum is equal to the target then print both the elements. //printing target sum pairs
        3.1.2 If the sum is less than the target then increase the left by 1
        3.1.3 Else decrease the right by 1
4.End loop.Thus, all the pairs has been printed .
*/

void targetSum(int *arr, int n, int target)
{
    sort(arr, arr + n);
    int left = 0;
    int right = n - 1;
    while (left < right)
    {
        int sum = arr[left] + arr[right];
        if (sum > target)
        {
            right--;
        }
        else if (sum < target)
        {
            left++;
        }
        else
        {
            cout << arr[left] << " and " << arr[right] << endl;
            left++;
            right--;
        }
    }
}
