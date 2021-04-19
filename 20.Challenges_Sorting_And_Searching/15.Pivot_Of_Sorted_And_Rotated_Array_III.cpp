#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>& arr) {
        int ans = 0;
        int start = 0, end = arr.size()-1;
        while(start<=end){
            int mid = (start+end)/2;
            if(arr[mid]<arr[0]){
                end = mid-1;
            }
            else{
                ans = mid;
                start = mid+1;
            }
        }
        return ans;
}

int main() {
	int n;
	cin >> n;
	vector<int> arr(n, 0);
	for(int i=0; i<n; i++){
		cin >> arr[i];
	}
	cout << solve(arr) << endl;
	return 0;
}