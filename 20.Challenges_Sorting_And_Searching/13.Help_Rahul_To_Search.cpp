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
*/

#include<bits/stdc++.h>
using namespace std;

int find(int arr[], int n, int key){
    int start = 0;
    int end = n-1;
    int i = 0;
    int j = n-1;
    while(i<=j)
    {
        int mid = (i + j)/2;

        if(arr[mid] == key)
            return mid;
        else if(arr[mid]>=arr[start]){
            if(arr[start]<=key && arr[mid]>=key){
                j = mid-1;
            }
            else{
                i = mid+1;
            }
        }
        else{
            if(arr[end]>=key && arr[mid]<=key){
                i = mid+1;
            }
            else
                j = mid-1;
        }
    }
    return -1;
}

int main() {

    int n;
    cin >> n;
    int a[n];
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    int key;
    cin >> key;

    cout << find(a, n, key) << endl;

    return 0;
}
