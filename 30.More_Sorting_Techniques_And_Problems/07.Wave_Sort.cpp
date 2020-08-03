#include<bits/stdc++.h>
using namespace std;

int main() {
    int a[] = {1, 3, 4, 2, 7, 4};
    //sort the array in wave form
    //Approach-1
    //Sort the array and swap alternate pairs
    //Time complexity - O(nlogn + n) = O(nlogn)

    //Approach-2
    int n = sizeof(a)/sizeof(a[0]);

    for(int i=0; i<n; i+=2){

        //Prev Element
        if(i != 0 and a[i]<a[i-1])
            swap(a[i], a[i-1]);

        //next element
        if(i!=(n-1) and a[i]<a[i+1])
            swap(a[i], a[i+1]);
    }

    return 0;
}
