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
