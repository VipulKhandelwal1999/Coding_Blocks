//Deque is best for insertion or deletion(expand or contract) from the ends
//Use list and forward list if you want to insert or delete from the middle
/*
Given an array and an integer k, find the maximum for each and every contiguous subarray of size k.

Input
the number n denoting number of elements in the array then after a new line we have the numbers of the array and then k in a new line

n < 10^6
k < 10^5
1 <= k <= n

and each element of the array is between 0 and 10^6

(Edited: In fact, n <= 10^5)

Output
print the output array

Example
Input:
9
1 2 3 1 4 5 2 3 6
3

Output:
3 3 4 5 5 5 6
*/

#include<bits/stdc++.h>
using namespace std;

int main(){

    int n;
    int a[100000];
    int k;

    cin >> n;
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    cin >> k;

    //We have to process first k elements seperately
    deque<int> Q(k);
    int i;
    for(i=0; i<k; i++){
        while(!Q.empty() && a[i]>a[Q.back()]){
            Q.pop_back();
        }
        Q.push_back(i);
    }

    //Process the remaining elements
    for(; i<n; i++){
        cout << a[Q.front()] << " ";

        //1. Remove the elements which are not the part of current window(Contraction)
        while(!Q.empty() && Q.front()<=i-k){
            Q.pop_front();
        }

        //2. Remove the elements which are not useful and are in window
        while(!Q.empty() && a[i]>=a[Q.back()]){
            Q.pop_back();
        }

        //3. Add the new elements(Expansion)
        Q.push_back(i);
    }
    cout << a[Q.front()] << endl;

    return 0;
}
