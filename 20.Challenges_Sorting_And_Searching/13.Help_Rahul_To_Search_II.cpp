/*
Rahul had a sorted array of numbers from which he had to find a given number quickly. His friend by mistake rotated the array. Now Rahul doesn't have time to sort the elements again. Help him to quickly find the given number from the rotated array.

Hint - Think Binary Search!



Input Format
The first line contains N - the size of the array. the next N lines contain the numbers of the array.The next line contains the item to be searched.

Constraints
Output Format
Output the index of number in the array to be searched. Output -1 if the number is not found.

Sample Input
5
4
5
1
2
3
2
Sample Output
3
Explanation
The given rotated array is [4, 5, 1, 2, 3]. The element to be searched is 2 whose index is 3.

Logic:-
Talking straightly, the Question is to find an element in the Sorted but Rotated array. One can imagine this Question by finding the pivot element and then rotate it to get the original array and can use Binary search to find the element but the main point to consider is that:-

FInding the Pivot element in the array is of the O(n), so why would you do such a lot of work, if it is so then you can also use Linear Search which will let you find the element in O(n), Where n is the number of elements in the array.
But You would get TLE as the constraint is quite large.
Here is the Algorithm that will let you find the element in O(log n)

1) Find middle point mid = (l + h)/2
2) If the key is present at the middle point, return mid.
3) Else If arr[l..mid] is sorted

  a) If the key to be searched lies in the range from arr[l] to
     arr[mid], recur for arr[l..mid].
  b) Else recur for arr[mid+1..r]
4) Else (arr[mid+1..r] must be sorted)

  a) If the key to be searched lies in the range from arr[mid+1]
     to arr[r], recur for arr[mid+1..r].
  b) Else recur for arr[l..mid]
*/

public static int search(int arr[], int l, int h, int key) {

    if (l > h)
        return -1;

    int mid = (l+h)/2;
    if (arr[mid] == key)
        return mid;

    // If arr[l...mid] is sorted
    if (arr[l] <= arr[mid]) {

        if (key >= arr[l] && key <= arr[mid])
            return search(arr, l, mid-1, key);

        return search(arr, mid+1, h, key);
    }

    if (key >= arr[mid] && key <= arr[h])
        return search(arr, mid+1, h, key);

    return search(arr, l, mid-1, key);
}
