/*
Given K painters to paint N boards where each painter takes 1 unit of time to paint 1 unit of boards i.e. if the length of a particular board is 5, it will take 5 units of time to paint the board. Compute the minimum amount of time to paint all the boards.

Note that:

Every painter can paint only contiguous segments of boards.
A board can only be painted by 1 painter at maximum.
Input Format
First line contains K which is the number of painters. Second line contains N which indicates the number of boards. Third line contains N space separated integers representing the length of each board.

Constraints
1 <= K <= 10
1 <= N <= 10
1<= Length of each Board <= 10^8

Output Format
Output the minimum time required to paint the board.

Sample Input
2
2
1 10
Sample Output
10
*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long

bool ifPossible(int board[], int n, int m, int cur_min)
{
    ll painter = 1, cur_sum = 0;
    for(int i=0;i<n;i++)
    {
        if(board[i] > cur_min)
            return false;

        if(cur_sum + board[i] <= cur_min)
            cur_sum += board[i];
        else
        {
            cur_sum = board[i];
            painter++;
            if(painter > m)
                return false;
        }
    }
    return painter <= m;
}
int minimumTime(int board[], int n, int m)
{
    ll low = *max_element(board,board+n),high=0;
    for(int i=0;i<n;i++)
        high+=board[i];

    ll ans=low;
    while(low<=high)
    {
        ll mid=(low+high)/2;

        if(ifPossible(board,n,m,mid))
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

    int k,n;
    cin >> k >> n;
    int board[n] = {0};
    for(int i=0; i<n; i++)
        cin >> board[i];

    cout<< minimumTime(board,n,k) << endl;

    return 0;
}
