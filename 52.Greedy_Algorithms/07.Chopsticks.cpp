// Link:- https://www.codechef.com/problems/TACHSTCK

#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll n, d;
    cin >> n >> d;
    vector<ll> arr(n, 0);
    for(ll i=0; i<n; i++){
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    ll count = 0;
    for(ll i=1; i<n; i++){
        if(arr[i]-arr[i-1] <=d){
            count++;
            i++;
        }
    }
    cout << count << "\n";

    return 0;
}