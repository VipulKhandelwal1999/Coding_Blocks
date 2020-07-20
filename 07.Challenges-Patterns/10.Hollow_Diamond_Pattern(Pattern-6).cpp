/*
Take N (number of rows), print the following pattern (for N = 5).

     * * * * *
     * *   * *
     *       *
     * *   * *
     * * * * *
Input Format
Constraints
0 < N < 10 (where N is an odd number)

Output Format
Sample Input
5
Sample Output
*	*	*       *      *
*	*	        *      *
* 	                       *
* 	*               *      *
* 	*	*       *      *
Explanation
Each '*' is separated from other by a tab.
*/
#include<iostream>

using namespace std;

int main()
{
     int i,j,k=0,n;
     cin>>n;
     for(i=0;i<n;i++)
     {
          if(i==0||i==n-1)
          {
               for(j=0;j<n;j++)
                    cout<<"*\t";
          }
          else if(i<=n/2)
          {
               for(j=0;j<(n/2)-i+1;j++)
               cout<<"*\t";
               for(j=0;j<2*i-1;j++)
               cout<<"\t";
               for(j=0;j<(n/2)-i+1;j++)
               cout<<"*\t";
               if(i==n/2)
                    k=2;
          }
          else
          {
               for(j=0;j<k;j++)
                    cout<<"*\t";
               for(j=0;j<n-(2*k);j++)
                    cout<<"\t";
               for(j=0;j<k;j++)
                    cout<<"*\t";
               k++;
          }
          cout<<"\n";
     }
}
