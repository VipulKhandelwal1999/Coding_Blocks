#include<bits/stdc++.h>
using namespace std;
#define ll long long

void permute(char in[], int i, set<string> &s)
{
    if(in[i]=='\0')
    {
        s.insert(in);
        return;
    }

    for(int j=i;in[j]!='\0';j++)
    {
        swap(in[i],in[j]);
        permute(in,i+1, s);
        //Backtracking - to restore the original array
        // jis swap se neeche aaye the use undo karna hoga
        swap(in[i],in[j]);
    }

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    char a[100];
    cin >> a;
    set<string> s;

    permute(a, 0, s);
    for(auto it:s)
        cout << it << " ";

    return 0;
}
