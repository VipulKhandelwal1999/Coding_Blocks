#include<bits/stdc++.h>
using namespace std;

int factorial(int n){
    int ans = 1;
    for(int i=1; i<=n; i++){
        ans = ans * i;
    }
    return ans;
}

int NCR(int n, int r){
    int ans = factorial(n)/(factorial(n-r)*factorial(r));
    return ans;
}

int main(){

    //NCR, and Factorial Of Number
    cout << factorial(5) << endl;

    return 0;
}
