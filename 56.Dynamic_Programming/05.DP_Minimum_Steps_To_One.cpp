/*
Minimum number of steps to reach from n to 1.We can take one of the steps given below in each steps
1.n = n/3 if n%3 == 0
2.n = n/2 if n%2 == 0
3.n = n-1
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll minSteps(ll n){
    //Base Case
    if(n == 1)
        return 0;

    //Recursive Case
    ll op1, op2, op3;
    op1 = op2 = op3 = INT_MAX;

    if(n%3 == 0){
        op1 =  minSteps(n/3);
    }
    if(n%2==0){
        op2 = minSteps(n/2);
    }
    op3 = minSteps(n-1);

    ll ans = min(min(op1, op2), op3) + 1;

    return ans;
}

int main() {

    ll n;
    cin >> n;

    cout << minSteps(n) << endl;

    return 0;
}
