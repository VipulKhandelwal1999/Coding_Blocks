#include<bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
//pbds will work as a set so it stores values in sorted order but we can get values through 
//index in methods like *st.find_by_order(i) or kth largest element in log(n) and one more 
//method st.order_of_key(k) will return number of elements lesser than k in O(logn)
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; 
#define ll long long
#define loop(i,a,b) for(ll i=a;i<b;i++)
#define v(a) vector<a>

void FasIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

int main(){
    FasIO();
    ll t=1;
    // cin >> t;
    loop(i,1,t+1){
        pbds st;
        st.insert(3);
        st.insert(4);
        st.insert(5);
        loop(i,0,st.size())
            cout << i << " " << *st.find_by_order(i) << endl; 
        cout << st.order_of_key(4) << endl; 
    }

    return 0;
}