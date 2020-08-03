/*
Given N, friends who want to go to a party on bikes. Each guy can go single or as a couple.
Find the number of ways in which N friends can go to the party.

*/
#include<bits/stdc++.h>
using namespace std;

int ways(int n){

    if(n<=1)
        return 1;

    return ways(n-1) + (n-1)*ways(n-2);

}

int main() {

    int n;
    cin >> n;
    cout << ways(n) << endl;

    return 0;
}
