#include<bits/stdc++.h>
using namespace std;

//Linear Search
template<typename T>
int search(T arr[], int n, int key){
    for(int p=0; p<n; p++){
        if(arr[p] == key)
            return p;
    }
    return n;
}

int main(){

    int a[] = {1,2,3,4,10,12};
    int n = sizeof(a)/sizeof(a[0]);
    int key = 10;
    cout << search(a,n,key) << endl;

    float b[] = {1.1, 1.2, 2.1};
    float k = 1.2;
    cout << search(b, 3, k) << endl;

    // search(book...)

    return 0;
}
