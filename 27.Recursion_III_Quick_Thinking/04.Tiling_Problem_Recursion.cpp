/*
// Place the tiles
Given a wall of size of 4 * N and tiles of size(1,4) and (4,1)
In how many ways you can build the wall?
*/

#include<bits/stdc++.h>
using namespace std;

int ways(int n){
    if(n<=3){
        return 1;
    }
    return ways(n-1) + ways(n-3);
}

int main(){
    int x;
    cin >> x;
    cout << ways(x) << endl;
}
