#include<bits/stdc++.h>
using namespace std;

//O(nlog(logn))
void prime_sieve(int *p, int n){
    for(int i=3; i<=n; i+=2){
        p[i] = 1;
    }
    for(int i=3; i<=n; i+=2){
        if(p[i] == 1){
            // Started Loop from i*i because there exist a divisor before root n which are divisor of n
            for(int j=i*i; j<=n; j+=i){
                    p[j] = 0;
            }
        }
    }
    p[1] = p[0] = 0;
    p[2] = 1;
}

int main(void){
    int n;
    cin >> n;
    int arr[n+1] = {0};
    prime_sieve(arr, n);
    for(int i=0; i<=n; i++){
        if(arr[i] == 1)
            cout << i << " ";
    }
    return 0;
}
