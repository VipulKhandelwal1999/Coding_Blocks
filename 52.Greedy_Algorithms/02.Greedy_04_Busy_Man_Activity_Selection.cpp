#include <bits/stdc++.h>
using namespace std;
int main()
{
      vector<pair<int,int> > SCHEDULE;
      vector<pair<int,int> > ::iterator itr;
      int t,n,i,a,b,ans,prevend;
      cin>>t;
      while(t--)
      {
             cin>>n;
             for(i=0;i<n;i++)
             {
                      cin>>a>>b;
                      SCHEDULE.push_back(make_pair(b,a));
             }
             sort(SCHEDULE.begin(),SCHEDULE.end());
              ans=0;
              prevend=-1;
              for(itr=SCHEDULE.begin();itr!=SCHEDULE.end();itr++)
              if(itr->second>=prevend)
             {
                      ans++;
                      prevend=itr->first;
              }
               cout<<ans<<endl;
               SCHEDULE.clear();
      }
       return 0;
}
