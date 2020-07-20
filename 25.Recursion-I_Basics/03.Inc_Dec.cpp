#include<bits/stdc++.h>
using namespace std;
void inc(int n){
    // Base Case
    if(n==0)
        return;

    // Recursive Case
    inc(n-1);
    cout << n << " "; // Bottom Up
}

void dec(int n){
    // Base Case
    if(n==0)
        return;

    // Recursive Case
    cout << n << " "; // Top Down
    dec(n-1);
}
int main(){
    int n;
    cin >> n;
    dec(n);
    cout << endl;
    inc(n);
    return 0;
}
