/*
Count Binary Strings of Length N, which have no consecutive ones?
*/
#include<bits/stdc++.h>
using namespace std;

int ways(int n){

    if(n==0)
        return 1;
    if(n==1)
        return 2;

    return ways(n-1) + ways(n-2);

}

int main() {

    int n;
    cin >> n;
    cout << ways(n) << endl;

    return 0;
}
