#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define loop(i,a,b) for(ll i=a;i<b;i++)

const ll mod = 1e9+7;
const ll prime = 31;

ll powr(ll a, ll n){
    ll res = 1;
    while(n){
        if(n&1ll){
            res *= a;
            res %= mod;
        }
        n /= 2;
        a *= a;
        a %= mod; 
    } 
    return res;
}

ll inv(ll a){
    //a^-1%m
    return powr(a, mod-2);
}

ll poly_hash_string(string s){
    ll p=31;
    ll p_powr=1;
    ll hash=0;
    for(ll i=0; i<s.size(); i++){
        hash += (p_powr * (s[i] - 'a' + 1));
        p_powr *= p;
        p_powr %= mod;
        hash %= mod;
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
        string text = "abababab", pat="aba";
        ll pat_hash = poly_hash_string(pat);
        ll n = text.size(), m=pat.size();
        ll pref[n];
        for(ll i=0; i<n; i++){
            pref[i] = (text[i] - 'a' + 1)*powr(prime, 31);
            pref[i] %= mod;
        }
        for(ll i=1; i<n; i++){
            pref[i] += pref[i-1];
            pref[i] %= mod;
        }
        
        for(ll i=0; i+m<=n; i++){
            //substring from [l...r]
            //r = i+m-1
            //l=i
            ll new_hash = pref[i+m-1];

            if(i-1>=0)
                new_hash -= pref[i-1];

            new_hash += mod;
            new_hash %= mod;
            if(new_hash ==(pat_hash*powr(prime, i))%mod){
                cout << i << "\n";
            }
        }
    }
    return 0;
}