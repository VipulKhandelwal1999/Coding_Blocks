/*
Length Of Longest Subarray Whose Sum Is k
*/

#include<iostream>
#include<unordered_map>
using namespace std;

int longestSubarraySum(int arr[], int n, int k){
    unordered_map<int, int> m;
    int pre = 0;
    int len = 0;
    for(int i=0; i<n; i++){
        pre += arr[i];

        if(pre == k){
            len = max(len, i+1);
        }
        if(m.find(pre) != m.end()){
            m[pre] = i;
        }
        if(m.find(pre-k) != m.end()){
            len = max(len, i-m[pre-k]);
        }
    }
    return len;
}

int main() {

    int n, k;
    cin >> n >> k;

    int arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    cout << longestSubarraySum(arr, n, k) << endl;

    return 0;
}
