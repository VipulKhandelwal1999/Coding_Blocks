// Link:- https://www.spoj.com/problems/EXPEDI/

#include<bits/stdc++.h>
using namespace std;
#define ll long long

bool comp(pair<ll, ll> a, pair<ll, ll> b){
    return a.first > b.first;
}

int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll t;
    cin >> t;
    while(t--){
        ll n, flag = 0, ans = 0;
        cin >> n;
        vector<pair<ll, ll>> arr;
        priority_queue<ll> pq;
        for(ll i=0; i<n; i++){
            ll x, y;
            cin >> x >> y;
            arr.push_back(make_pair(x, y));
        }
        ll l, p;
        cin >> l >> p;

        sort(arr.begin(), arr.end(), comp);

        // Distance of the fuel station from the truck
        for(ll i=0; i<n; i++){
            arr[i].first = l-arr[i].first;
        }

        // prev denotes previous city we have visited
        ll prev = 0;
        ll x = 0; // current city
        while(x < n){
            // If we have enough fuel to visit the next city
            if(p>=(arr[x].first-prev)){
                p = p-(arr[x].first-prev);
                pq.push(arr[x].second);
                prev = arr[x].first;
            }
            else{
                // check if some fueling station visited in the priority queue
                if(pq.empty()){
                    flag = 1;
                    break;
                }
                
                // Refuel the truck with fuel stations of higher capacity
                p += pq.top();
                pq.pop();
                ans++;
                continue;
            }
            x++;
        }
        // Actually Travelled n refuel stations
        if(flag == 1){
            cout << "-1\n";
            continue;
        }
        else{
            l = l-arr[n-1].first;
            if(p >= l){
                cout << ans << "\n";
            }
            else{
                while(p < l){
                    if(pq.empty()){
                        flag = 1;
                        break;
                    }
                    p += pq.top();
                    pq.pop();
                    ans++;
                }
                if(flag == 1){
                    cout << "-1\n";
                    continue;
                }
                else{
                    cout << ans << "\n";
                }
            }
        }
    }

    return 0;
}