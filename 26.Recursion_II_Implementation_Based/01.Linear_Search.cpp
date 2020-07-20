#include<bits/stdc++.h>
using namespace std;

int linearSearch(int *a, int n, int key){
    // Base Case
    if(n==0){
        return -1;
    }

    //Recursive Case
    if(a[0] == key){
        return 0;
    }
    int i = linearSearch(a+1, n-1, key);
    if(i==-1){
        return -1;
    }
    return i+1;
}

//Approach-II
int linear_search(int *a, int i, int n, int key){
    // Base Case
    if(i == n)
        return -1;

    //Recursive Case
    if(a[i] == key)
        return i;

    return linear_search(a, i+1, n, key);
}


int main(){
    int arr[] = {1,3,4,5,2};
    cout << linearSearch(arr, 5, 2) << endl;
    cout << linear_search(arr, 0, 5, 89) << endl;
    return 0;
}
