// Find the minimum length of wire needed to join all the white dots with a black dot.

#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){

    ll n;
    cin >> n;
    vector<ll> white(n), black(n);
    for(auto &x: white)
        cin >> x;
    for(auto &x: black)
        cin >> x;
    sort(white.begin(), white.end());
    sort(black.begin(), black.end());
    ll sum = 0;
    for(ll i=0; i<n; i++){
        sum += abs(white[i] - black[i]);
    }
    cout << sum << "\n";

    return 0;
}