#include<bits/stdc++.h>
using namespace std;

int maxSubarraySum(int arr[], int n){
    
    // Your code here
    int sum = 0;
    int ans = INT_MIN;
    for(int i=0; i<n; i++){
        sum += arr[i];
        if(sum > ans)
            ans = sum;
        if(sum < 0)
            sum = 0;
    }
    return ans;
    
}

int main() {
	int t,n;
	cin >> t;

	while(t--){
		cin >> n;
		int a[n];
		int currentSum = 0, maxSum = INT_MIN;
		for(int i=0; i<n; i++)
			cin >> a[i];

		for(int i=0; i<n; i++){
			currentSum += a[i];
			if(currentSum > maxSum){
				maxSum = currentSum;
			}
			if(currentSum < 0){
				currentSum = 0;
			}
		}
		cout << maxSum << endl;
	}
	return 0;
}
