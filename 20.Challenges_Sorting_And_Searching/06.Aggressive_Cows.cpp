/*
Farmer John has built a new long barn, with N (2 <= N <= 100,000) stalls. The stalls are located along a straight line at positions x1,…,xN (0 <= xi <= 1,000,000,000).

His C (2 <= C <= N) cows don't like this barn layout and become aggressive towards each other once put into a stall. To prevent the cows from hurting each other, FJ wants to assign the cows to the stalls, such that the minimum distance between any two of them is as large as possible. What is the largest minimum distance?

Input Format
First line contains N and C, separated by a single space, representing the total number of stalls and number of cows respectively. The next line contains N integers containing the indexes of stalls.

Constraints
2 <= N <= 100,000
0 <= xi <= 1,000,000,000
2 <= C <= N

Output Format
Print one integer: the largest minimum distance.

Sample Input
5 3
1 2 8 4 9
Sample Output
3
Explanation
Problem Credits - (Spoj)[http://www.spoj.com/problems/AGGRCOW/]
*/

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
