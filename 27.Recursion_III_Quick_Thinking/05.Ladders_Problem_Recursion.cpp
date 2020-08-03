/*
You are given a ladder of size n and you can take a maximum jump of size k. In how many ways you can reach to the top?
*/

#include<bits/stdc++.h>
using namespace std;

int f(int n, int k){
    if(n==0)
        return 1;
    if(n < 0)
        return 0;

    int ans = 0;
    for(int i = 1; i<= k; i++){
        ans += f(n-i, k)
    }
    return ans;
}

int main() {

    int n, k;
    cin >> n >> k;

    return 0;
}
