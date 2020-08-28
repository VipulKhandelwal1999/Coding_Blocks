/*
Given three numbers a,b,c. Calculate (a^b)mod c.

Input Format
Single line containing three integers a,b,c separated by space.

Constraints
1<=a,b,c<=100000

Output Format
Print (a^b)mod c.

Sample Input
2 2 3
Sample Output
1
Explanation
(2^2)mod 3=4 mod 3 = 1

Logic:-
We just need to modify the logarithmic power function to handle overflow using modulo arithmetic.
Refer the below code where we have using the modulo arithmetic property which is (ab) mod p = ( (a mod p) (b mod p) ) mod p
*/

#include <bits/stdc++.h>
using namespace std;

#define boost  ios_base::sync_with_stdio(false);
#define endl '\n'
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define ll long long
#define ull unsigned long long
#define max(a,b) ((a>b)?(a):(b))
#define min(a,b) ((a<b)?(a):(b))

//values
#define MAX 100005
#define inf LLONG_MAX
#define MIN INT_MIN
#define PIE 3.141592653589793238

ll gcd(ll a , ll b){return b==0?a:gcd(b,a%b);}

/*..................................................................................................................................*/

ll mod;
ll powmod(ll a,ll b)
{
    ll res=1;
    if(a>=mod)a%=mod;
    for(;b;b>>=1)
        {
            if(b&1)
                res=res*a;
            if(res>=mod)
                res%=mod;
            a=a*a;
            if(a>=mod)a%=mod;
        }
    return res;
}

int main()
{
    int a,b;cin>>a>>b>>mod;
    cout<<powmod(a,b);
    return 0;
}
