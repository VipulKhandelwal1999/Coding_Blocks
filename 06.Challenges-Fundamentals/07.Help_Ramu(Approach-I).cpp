/*
Ramu often uses public transport. The transport in the city is of two types: cabs and rickshaws. The city has n rickshaws and m cabs, the rickshaws are numbered by integers from 1 to n, the cabs are numbered by integers from 1 to m.

Public transport is not free. There are 4 types of tickets:

A ticket for one ride on some rickshaw or cab. It costs c1 ruppees;
A ticket for an unlimited number of rides on some rickshaw or on some cab. It costs c2 ruppees;
A ticket for an unlimited number of rides on all rickshaws or all cabs. It costs c3 ruppees;
A ticket for an unlimited number of rides on all rickshaws and cabs. It costs c4 ruppees.

Ramu knows for sure the number of rides he is going to make and the transport he is going to use. He asked you for help to find the minimum sum of ruppees he will have to spend on the tickets.

Input Format
Each Test case has 4 lines which are as follows:


Output Format
For each testcase , print a single number - the minimum sum of rupees Ramu will have to spend on the tickets in a new line.

Sample Input
2
1 3 7 19
2 3
2 5
4 4 4
4 3 2 1
1 3
798
1 2 3
Sample Output
12
1
Explanation
For the first testcase ,
The total cost of rickshaws = min( min(2 * 1, 3) + min(5 * 1, 3), 7) = min(5, 7) = 5
The total cost of cabs = min( min(4 * 1, 3) + min(4 * 1, 3) + min(4 * 1, 3) , 7) = min ( 9, 7) = 7
Total final cost = min( totalCabCost + totalRickshawCost , c4) = min( 5 + 7, 19) = min ( 12, 19) = 12
We print 12.

*/

#include<bits/stdc++.h>
using namespace std;
int mincost(int c1,int c2,int c3,int c4,int r,int c,int a[],int b[])
{
    int cost2=0,cost3,cost4,i;
    for(i=0;i<r;i++)
    {
        cost2 += min((a[i]*c1),c2);
    }
    cost3 = min(cost2,c3);
    cost2 = 0;
    for(i=0; i<c; i++)
    {
        cost2 += min((b[i]*c1),c2);
    }
    cost3 += min(cost2,c3);
    cost4 = min(cost3,c4);
    return cost4;
}
int main() {

	int t;
    int c1,c2,c3,c4,r,c;

	cin >> t;

    while(t--)
    {
        cin >> c1 >> c2 >> c3 >> c4;
        cin >> r >> c;
        int a[r], b[c];
        for(int i=0;i<r;i++)
        {
            cin >> a[i];
        }
        for(int j=0; j<c; j++)
        {
            cin >> b[j];
        }
        int cost= mincost(c1,c2,c3,c4,r,c,a,b);
        cout << cost << "\n";
    }
	return 0;
}
