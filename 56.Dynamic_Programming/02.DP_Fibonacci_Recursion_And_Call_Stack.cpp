/*
Time Complexity - O(2^n)
Space Complexity - O(n) - Internal Stack Space
*/

#include<bits/stdc++.h>
using namespace std;

int fib(int n){
    //Base case
    if(n == 0 || n == 1){
        return n;
    }

    int ans;
    ans = fib(n-1) + fib(n-2);

    return ans;
}

int main() {

    int n;
    cin >> n;

    cout << fib(n) << endl;

    return 0;
}
