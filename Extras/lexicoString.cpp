#include<bits/stdc++.h>
using namespace std;
#define ll long long

void lexico(ll x, ll n){

    //base case
    if(x>n) return;
    if(x==n){
        cout << x << "\n";
        return;
    }

    //self work
    if(x != 0)
        cout << x << "\n";

    //recursive task
    for(ll i= (x==0)?1:0; i<=9; i++){
        lexico(10*x+i, n);
    }
}

int main(){
    lexico(0, 13);
    return 0;
}