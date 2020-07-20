#include<bits/stdc++.h>
using namespace std;

//Approach-I
int lastOccurence(int *a, int n, int key){

    // Base Case
    if(n == -1)
        return -1;
    //Recursive Case
    if(a[n] == key)
        return n;

    return lastOccurence(a, n-1, key);
}

//Approach-II
int last_occurence(int *a, int n, int key){
    // Base Case
    if(n==0){
        return -1;
    }
    //Recursive Case
    int i = last_occurence(a+1, n-1, key);
    if(i == -1){
        if(a[0] == key)
            return 0;
        else
            return -1;
    }
    //otherwise if i returned by subproblem is not -1
    return i+1;
}


int main(){
    int arr[] = {1,3,4,5,2};
    cout << lastOccurence(arr, 4, 89) << endl;
    cout << last_occurence(arr, 4, 89) << endl;

    return 0;
}
