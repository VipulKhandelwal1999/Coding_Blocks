/*
Deepak is learning Sieve of Eratosthenes, He is stuck somewhere. Help him printing prime numbers.

Input Format
Single line containing integral value n.

Constraints
1<=n<=500000

Output Format
Integral value denoting nth prime number.

Sample Input
1
Sample Output
2
*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long

void prime_sieve(ll p[], ll n){
    for(ll i=3; i<=n; i+=2){
        p[i] = 1;
    }
    for(ll i=3; i<=n; i+=2){
        if(p[i] == 1){
            for(ll j=i*i; j<=n; j+=i){
                    p[j] = 0;
            }
        }
    }
    p[1] = p[0] = 0;
    p[2] = 1;
}

int main(){

	ll n;
	cin >> n;
	ll arr[1000000] = {0};
	prime_sieve(arr,1000000);
	ll count = 0;
	for(ll i=2; i<1000000; i++){
		if(arr[i] == 1){
			count++;
			if(count == n){
				cout << i << endl;
				break;
			}
		}
	}
	return 0;
}
