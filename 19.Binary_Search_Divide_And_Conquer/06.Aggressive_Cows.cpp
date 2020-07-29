#include<bits/stdc++.h>
using namespace std;

bool solve(int arr[], int n, int cows, int key){
    int last_cow = arr[0];
    int count = 1;
    for(int i=1; i<n; i++){
        if(arr[i]-last_cow >= key){
            last_cow = arr[i];
            count++;
            if(count == cows)
                return true;
        }
    }
    return false;

}

int main(){

    int n, c;
    cin >> n >> c;

    int arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    sort(arr, arr+n);
    int low = 0;
    int high = arr[n-1] - arr[0];
    int ans = 0;

    while(low <= high){
        int mid = (low + high)/2;
        bool cowsRakhPaaye = solve(arr, n, c, mid);
        if(cowsRakhPaaye){
            ans = mid;
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }

    }
    cout << ans << endl;
    return 0;
}
