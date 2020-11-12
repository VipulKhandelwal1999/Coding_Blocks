#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define loop(i,a,b) for(ll i=a;i<b;i++)
ll poly_hash_string(string s){
    ll p=31, m=1e9+7;
    ll p_powr=1;
    ll hash=0;
    for(ll i=0; i<s.size(); i++){
        hash += (p_powr * (s[i] - 'a' + 1));
        p_powr *= p;
        p_powr %= m;
        hash %= m;
    }
    return hash;
}

void FasIO(){  
    #ifndef ONLINE_JUDGE 
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout); 
    #endif 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}
int main(){
    FasIO();
    ll t=1;
    // cin >> t;
    loop(i,1,t+1){
        string s = "abababab";
        ll s_hash = poly_hash_string(s);
        cout << s_hash << endl;
    }
    return 0;
}