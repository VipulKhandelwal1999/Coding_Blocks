#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
//pbds *st.find_by_order(k) or kth largest element in log(n) and 
//st.order_of_key(k) will return number of elements lesser than k in O(logn)
#define ll long long
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds; 
#define ld long double
#define loop(i,a,b) for(ll i=a;i<b;i++)
#define f first
#define s second
#define pll pair<ll, ll>
#define pb push_back
#define pob pop_back
#define mp make_pair
#define v(a) vector<a> 
#define sort(a) sort(a.begin(), a.end())
ll gcd(ll a, ll b){
    if (b == 0)
        return a;
    return gcd(b, a % b); 
     
}
pll Egcd(ll x, ll y){
    if(x==0)
        return mp(0,1);
    pll t = Egcd(y%x, x);
    return mp(t.s-t.f*(y/x), t.f);
}
ll powerm(ll x, ll y, ll m){
    ll ans=1, r=1;
    x%=m;
    while(r>0&&r<=y){
        if(r&y){
            ans*=x;
            ans%=m;
        }
        r<<=1;
        x*=x;
        x%=m;
    }
    return ans;
}
ll lcm(ll a, ll b){
    return a*b/gcd(a, b);
}
ll power(ll x, ll n){
    if(n==0)
        return 1;
    ll pow = power(x, n/2);
    if(n & 1)
        return x*pow*pow;
    return pow*pow;
}
ll floor_sqrt(ll x){     
    // Base cases 
    if (x == 0 || x == 1)  
       return x; 
    // Do Binary Search for floor(sqrt(x)) 
    ll start = 1, end = x, ans;    
    while(start <= end){         
        int mid = (start + end) / 2;
        // If x is a perfect square 
        if (mid*mid == x) 
            return mid;
        // Since we need floor, we update answer when mid*mid is  
        // smaller than x, and move closer to sqrt(x) 
        if (mid*mid < x){ 
            start = mid + 1; 
            ans = mid; 
        }  
        else // If mid*mid is greater than x 
            end = mid-1;         
    } 
    return ans; 
} 
v(ll) prime_sieve(ll n){
    v(ll) p(n+1, 0);
    for(ll i=3; i<=n; i+=2){
        p[i] = 1;
    }
    for(ll i=3; i<=n; i+=2){
        if(p[i] == 1){
            for(ll j=i*i; j<=n; j+=i){
                p[j] = 0;
            }
        }
    }
    p[1] = p[0] = 0;
    p[2] = 1;
    return p;
}
v(ll) prime_numbers(ll n){
    v(ll) primes = prime_sieve(n);
    v(ll) prime_array(n,0);
    ll count = 0;
    for(ll i=2; i<=n; i++){
        if(primes[i]==1){
            prime_array[count] = i;
            count++;
        }
    }
    prime_array.resize(count);
    return prime_array;
}
v(ll) factorize(ll m){
    v(ll) factors;
    ll num = floor_sqrt(m)+2;
    v(ll) primes = prime_numbers(num);
    factors.clear();
    ll i = 0;
    ll p = primes[0];
    while(p*p <= m){
        if(m%p == 0){
            while(m%p == 0){
                factors.push_back(p);
                m = m/p;
            }
        }
        i++;
        p = primes[i];
    }
    if(m != 1){
        factors.push_back(m);
    }
    return factors;
}
ll no_of_divisors(ll m){
    ll num = floor_sqrt(m)+2;
    v(ll) primes = prime_numbers(num);
    int i = 0;
    int p = primes[0];
    int ans = 1;

    while(p*p <= m){
        if(m%p == 0){
            int count = 0;
            while(m%p == 0){
                count++;
                m = m/p;
            }
            ans = ans*(count + 1);
        }
        i++;
        p = primes[i];
    }
    if(m != 1){
        ans = ans * 2;
    }
    return ans;
}
v(ll) build_segment_tree(v(ll) &arr){
    ll n = arr.size();
    v(ll) tree(4*n);
    // insert leaf nodes in tree 
    loop(i,0,n)    
        tree[n+i] = arr[i];
    // build the tree by calculating parents 
    for(ll i=n-1;i>0;--i)      
        tree[i] = tree[i<<1] + tree[i<<1 | 1];  
    //equivalent to tree[i]=tree[2*i]+tree[2*i+1]
    return tree;
}
void update_segment_tree(v(ll) &tree, ll p, ll value){  
    // set value at position p
    ll n = tree.size()/4;
    tree[p+n] = value; 
    p = p+n;
    // move upward and update parents 
    for(ll i=p; i>1; i>>=1) 
        tree[i>>1] = tree[i] + tree[i^1]; 
}
ll query_segment_tree(vector<ll> &tree, ll l, ll r){  
    ll n = tree.size()/4;
    ll res = 0;
    // loop to find the sum in the range 
    for(l += n, r += n; l < r; l >>= 1, r >>= 1){ 
        if (l&1)
            res += tree[l++]; 
        if (r&1)  
            res += tree[--r]; 
    }
    return res; 
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
        ll s=1, e=1e6;
        string str;
        ll ans = 0;
        while(s<=e){
            ll mid = (s+e)/2;
            cout << mid << endl;
            cin >> str;
            if(str == ">="){
                ans = mid;
                s = mid+1;
            } 
            else{
                e = mid-1;
            }
        }
        cout << "! " << ans << endl;
    }
    return 0;
}