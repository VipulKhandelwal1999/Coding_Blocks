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
        ll text_hash = poly_hash_string(text.substr(0,m));

        if(text_hash == pat_hash)
            cout << "0" << "\n";
        
        for(ll i=1; i+m<=n; i++){
            ll new_hash = text_hash;
            //[i-1] th
            //removed the [i-1] character
            new_hash = (new_hash - (text[i-1] - 'a' + 1) + mod) % mod;

            // second step
            new_hash *= inv(prime);
            new_hash %= mod;

            //third step
            new_hash = new_hash + (text[i+m-1] - 'a' + 1)*powr(prime, m-1);
            new_hash %= mod;

            if(new_hash == pat_hash){
                cout << i << "\n";
            }
            text_hash = new_hash;
        }
    }
    return 0;
}