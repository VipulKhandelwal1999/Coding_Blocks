/*
You are given N elements, a1,a2,a3….aN. Find the number of good sub-arrays.
A good sub-array is a sub-array [ai,ai+1,ai+2….aj] such that (ai+ai+1+ai+2+….+aj) is divisible by N.



Input Format
The first line contains the number of test cases T. First line of each test case contains an integer N denoting the number of elements. Second line of each test case contains N integers, a1, a2, a3….aN, where ai denotes the ith element of the array.

Constraints
1<=T<=10
1<=N<=10^5
|ai|<=10^9

Output Format
Output a single integer denoting the number of good sub-arrays.

Sample Input
2
5
1 1 1 1 1
5
5 5 5 5 5
Sample Output
1
15
Explanation
In first test case, there is only one sub-array [1, 1, 1, 1, 1], such that 1+1+1+1+1=5, which is divisible by N=5

Logic:-
Let there be a subarray (i, j) whose sum is divisible by k sum(i, j) = sum(0, j) - sum(0, i-1) Sum for any subarray can be written as q*k + rem where q is a quotient and rem is remainder Thus,
sum(i, j) = (q1 * k + rem1) - (q2 * k + rem2) sum(i, j) = (q1 - q2)k + rem1-rem2

We see, for sum(i, j) i.e. for sum of any subarray to be divisible by k, the RHS should also be divisible by k. (q1 - q2)k is obviously divisible by k, for (rem1-rem2) to follow the same, rem1 = rem2 where rem1 = Sum of subarray (0, j) % k rem2 = Sum of subarray (0, i-1) % k So if any sub-array sum from index i’th to j’th is divisible by k then we can saya[0]+…a[i-1] (mod k) = a[0]+…+a[j] (mod k)

The above explanation is provided by Ekta Goel.

So we need to find such a pair of indices (i, j) that they satisfy the above condition. Here is the algorithm :

Make an auxiliary array of size k as Mod[k] . This array holds the count of each remainder we are getting after dividing cumulative sum till any index in arr[]. Now start calculating cumulative sum and simultaneously take it’s mod with K, whichever remainder we get increment count by 1 for remainder as index in Mod[] auxiliary array. Sub-array by each pair of positions with same value of ( cumSum % k) constitute a continuous range whose sum is divisible by K. Now traverse Mod[] auxiliary array, for any Mod[i] > 1 we can choose any to pair of indices for sub-array by (Mod[i]*(Mod[i] – 1))/2 number of ways . Do the same for all remainders < k and sum up the result that will be the number all possible sub-arrays divisible by K.

You can refer this Video for video solution for the problem.

Program for finding good subarray is given below:
*/

#include <iostream>
#include <stdlib.h>
#include <cstring>

#define ff first
#define se second
#define pb push_back
#define nn 100010
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
#define cmp 1e-16
using namespace std;

ll a[nn],pre[nn];

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
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        ll sum=0;
        memset(pre,0,sizeof pre);
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            sum+=a[i];
            sum%=n;
            sum=(sum+n)%n;
            pre[sum]++;
        }
        ll ans=(pre[0]*(pre[0]+1))/2;
        for(int i=1;i<n;i++)
        {
            ans+=(pre[i]*(pre[i]-1))/2;
        }
        cout<<ans<<endl;
    }
    return 0;
}
