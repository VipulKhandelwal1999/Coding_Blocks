/*
    //Inclusion Exclusion
    How many numbers are there which are less than 1000 and are divisible by 2, 3 and 5?
*/

#include<bits/stdc++.h>
using namespace std;

int main() {

    int a = floor(999/2);
    int b = floor(999/3);
    int c = floor(999/5);
    int d = floor(999/6);
    int e = floor(999/15);
    int f = floor(999/10);
    int g = floor(999/30);
    int ans = a + b + c - d - e - f + g;

    cout << ans << endl;

    return 0;
}
