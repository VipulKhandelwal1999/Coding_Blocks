#include<bits/stdc++.h>
using namespace std;

//Approach-I (Recursive + Iteration)
void bubbleSort(int *arr, int n){

    //Base Case
    if(n==1)
        return;

    //Recursive Case
    //After You have moved the largest element in the current part to the end of array by pairwise swapping
    for(int j=0; j<n-1; j++){
        if(arr[j] > arr[j+1]){
            swap(arr[j], arr[j+1]);
        }
    }
    //sort the first n-1 elements
    bubbleSort(arr, n-1);
}

//Approach-II (Recursive)
void bubble_sort(int *arr, int j, int n){

    //Base Case
    if(n==1)
        return;

    if(j == n-1){
        //single pass of the current array to be done
        return bubble_sort(arr, 0, n-1);
    }
    //rec case
    if(arr[j] > arr[j+1])
        swap(arr[j], arr[j+1]);

    //sort the first n-1 elements
    bubble_sort(arr, j+1, n);
    return;
}

int main(){



    return 0;
}
