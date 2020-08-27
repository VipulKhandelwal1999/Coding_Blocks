/*
You are given two integers n and k. Find the greatest integer x, such that, x^k <= n.

Input Format
First line contains number of test cases, T. Next T lines contains integers, n and k.

Constraints
1<=T<=10
1<=N<=10^15
1<=K<=10^4

Output Format
Output the integer x

Sample Input
2
10000 1
1000000000000000 10
Sample Output
10000
31
Explanation
For the first test case, for x=10000, 10000^1=10000=n
*/

/*We will aplly binary search in this problem. For every possible mid obtained by using binary search we will check of it is the best suitable candidate or not for becoming the Kth root and then we reduce the search space of the binary search according to the mid value. If mid^k is greater than N then we will find the best suitable value from left to mid-1 otherwise we will find much larger value by finding it from mid+1 to right.

*/
#include <bits/stdc++.h>
#define ff first
#define se second
#define pb push_back
#define nn 6000
#define mt make_tuple
#define mp make_pair
#define ll long long int
#define db double
#define ldb long double
#define inf 1000000000000000000ll
#define logn 20
#define mod 1000000007ll
#define mod1 mod
#define mod2 100000009ll
#define sqr(a) a*1ll*a
#define nullp mp(-1,-1)
#define set0(a) memset(a,0,sizeof a)
#define init(a) memset(a,-1,sizeof a)
#define cmp 1e-16

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif
    int t;
    ll n,k;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        if(k==1)
        {
            cout<<n<<endl;
            continue;
        }
        ll l=1,r=100000000,mid;
        while(l<r)
        {
            mid=l+r+1>>1;
            bool flag=1;
            ll tmp=1;
            for(int i=1;i<=k;i++)
            {
                tmp*=mid;
                if(tmp>n)
                {
                    flag=0;
                    break;
                }
            }
            if(flag)
                l=mid;
            else
                r=mid-1;
        }
        cout<<r<<endl;
    }
    return 0;
}
