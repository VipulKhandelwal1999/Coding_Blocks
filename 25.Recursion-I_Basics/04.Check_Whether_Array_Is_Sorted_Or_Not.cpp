#include<bits/stdc++.h>
using namespace std;

int Check_Sorted(int *arr, int n){
    if(n==0 || n==1){
        return true;
    }

    if(arr[0] < arr[1] and Check_Sorted(arr+1, n-1)){
        return true;
    }

    return false;
}

int main(){
    int arr[] = {1,2,3,14,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << Check_Sorted(arr, n) << endl;

    return 0;
}
