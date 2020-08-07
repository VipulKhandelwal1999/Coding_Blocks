/*
Longest Consecutive Subsequence
Approach-I:
Sort(O(nlogn))
Then add length upto we are getting consecutive elements with all distinct
Approach-II:
Loop from minimum to maximum and for each number we will check whether a number is present or not if present count++ and change maximum = max(count, maximum) else
count = 0
At last print count
*/

#include<bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin >> n;
    int arr[n];

    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    sort(arr, arr+n);
    int maxi = 1;
    set<int> s;
    s.insert(arr[0]);
    for(int i=1; i<n; i++){
        if((arr[i]-arr[i-1] == 1) || (arr[i]-arr[i-1] == 0)){
            s.insert(arr[i]);
            int sizea = s.size();
            maxi = max(maxi, sizea);
        }
        else{
            s.clear();
            s.insert(arr[i]);
            int sizea = s.size();
            maxi = max(maxi, sizea);
        }
    }
    cout << maxi << endl;

    return 0;
}
