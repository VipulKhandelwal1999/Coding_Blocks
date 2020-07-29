/*
Inclusion-Exclusion Principle
How many numbers from 1 to 100 are multiple of 2 or 3?
|AUB| = |A| + |B| - |A^B|
|A| = floor(100/2)
|B| = floor(100/3)
|A^B| = floor(100/6)

ans = |A| + |B| - |A^B|

General trend when combining even terms subtract them when combining odd terms add them

*/

#include<bits/stdc++.h>
using namespace std;


int main() {
    cout << floor(100/2) + floor(100/3) - floor(100/6) << endl;
    return 0;
}
