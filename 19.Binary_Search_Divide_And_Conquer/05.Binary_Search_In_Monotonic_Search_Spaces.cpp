
/*    Find squareroot of a number upto p precision using binary search expected time complexity O(logn + p)*/

#include<bits/stdc++.h>
using namespace std;

float squareroot(int n, int p)
{
    float ans = 0;
    float low = 0, high = n;
    while(low <= high)
    {
        int mid = (low + high)/2;
        if(mid*mid == n)
        {
            ans = mid;
            return ans;
        }
        else if(mid*mid < n)
        {
            low = mid + 1;
            ans = mid;
        }
        else
            high = mid - 1;
    }

    //Floating Part
    //Brute Force

    float inc = 0.1;
    for(int i=0; i<p; i++)
    {
        while(ans*ans <= n)
        {
            ans += inc;

        }
        //Overshot the value
        ans -= inc;
        inc /= 10;
    }
    return ans;

}
int main()
{
    int n, p;
    n = 10;
    p = 3;
    cout << squareroot(n,p);

    return 0;
}
