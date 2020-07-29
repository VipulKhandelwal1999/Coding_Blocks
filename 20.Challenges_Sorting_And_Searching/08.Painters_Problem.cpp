/*
You have to paint N boards of length {A0, A1, A2, A3 … AN-1}. There are K painters available and you are also given how much time a painter takes to paint 1 unit of board. You have to get this job done as soon as possible under the constraints that any painter will only paint contiguous sections of board. Return the ans % 10000003

Input Format
First line contains three space seperated integers N,K and T ,where
N = Size of array,
K = No of painters available ,
T = Time taken to print each board by one painter
Next line contains N space seperated positive integers denoting size of N boards.

Constraints
1<=N<=100000
1<=K<=100000
1<=T<=1000000
1<=Li<=100000

Output Format
Return minimum time required to paint all boards % 10000003.

Sample Input
2 2 5
1 10
Sample Output
50
Explanation
The first painter can paint the first board in 5 units of time and the second painter will take 50 units of time to paint the second board. Since both can paint simultaneously , the total time required to paint both the boards is 50.
*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long

bool ifPossible(ll board[], ll n, ll m, ll cur_min, ll t)
{
    ll painter = 1, cur_sum = 0;
    for(ll i=0; i<n; i++)
    {
        if(t*board[i] > cur_min)
            return false;

        if(cur_sum + t*board[i] <= cur_min)
            cur_sum += (t*board[i]);
        else
        {
            cur_sum = t*board[i];
            painter++;
            if(painter > m)
                return false;
        }
    }
    return painter <= m;
}
ll minimumTime(ll board[], ll n, ll m, ll t)
{
    ll low = *max_element(board,board+n),high=0;
    for(ll i=0;i<n;i++)
        high += (t*board[i]);

    ll ans=low;
    while(low<=high)
    {
        ll mid=(low+high)/2;

        if(ifPossible(board,n,m,mid, t))
        {
            ans=mid;
            high=mid-1;
        }
        else
            low=mid+1;
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n, k, t;
    cin >> n >> k >> t;
    ll board[n] = {0};
    for(ll i=0; i<n; i++)
        cin >> board[i];

    cout<< minimumTime(board,n,k, t)%10000003 << endl;

	return 0;
}
