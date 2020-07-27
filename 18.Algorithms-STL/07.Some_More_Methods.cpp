#include<bits/stdc++.h>
using namespace std;
int main(){
    int a, b;
    a = 2;
    b = 3;
    swap(a, b);
    cout << a << " " << b;
    cout << endl;

    cout << max(a, b) << endl;
    cout << min(a, b) << endl;

    int arr[] = {1,2,3,4,4,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    swap(arr[0], arr[1]);
    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    reverse(arr, arr+4);
    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
