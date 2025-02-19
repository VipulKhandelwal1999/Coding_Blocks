/*
ou are given a sorted but rotated array. You need to fine the index of the pivot element of the array where pivot is that element in the array which is greater than its next element and divides the array into two monotonically increasing halves.

Input Format
The first line denotes N - the size of the array. The following N lines each denote the numbers in the array.

Constraints
Output Format
Output the index of the pivot of the array.

Sample Input
5
4
5
1
2
3
Sample Output
1
Explanation
Here, 5 is the pivot element. Thus the output is 1 which is 5's index.

Logic:-
Find middle point mid = (l + h)/2
If key is present at middle point, return mid.
Else If arr[l..mid] is sorted
a) If key to be searched lies in range from arr[l] to arr[mid], recur for arr[l..mid].
b) Else recur for arr[mid+1..r]
Else (arr[mid+1..r] must be sorted) .
a) If key to be searched lies in range from arr[mid+1] to arr[r], recur for arr[mid+1..r].
b) Else recur for arr[l..mid]
*/


#include<iostream>
using namespace std;

int* getArray(int n){
    int *arr = new int[n];
    for(int i = 0; i < n;++i){
        cin>>arr[i];
    }
    return arr;
}

int findPivot(int *arr,int low,int high){
    if(low>high){
        return -1;
    }
    else
    if(low==high){
        return low;
    }
    int mid = (low + high)/2;
    if(mid < high && arr[mid] > arr[mid+1]){
        return mid;
    }
    if(mid > low && arr[mid] < arr[mid-1]){
        return mid-1;
    }
    if(arr[low] >= arr[mid]){
        return findPivot(arr,low,mid-1);
    }
    return findPivot(arr,mid+1,high);
}

int main() {
    int n;
    cin>>n;
    int *arr = getArray(n);
    int pivot = findPivot(arr,0,n-1);
    cout<<pivot<<endl;
    return 0;
}
