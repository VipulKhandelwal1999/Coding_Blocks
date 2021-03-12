#include<bits/stdc++.h>
using namespace std;
#define ll long long

void paranthesisGeneraion(string output, ll n, ll c, ll o){
    if(output.size()==n){
        cout << output << "\n";
        return;
    }
    if(o<n/2){
        paranthesisGeneraion(output+'(', n, c, o+1);
    }
    if(c<o){
        paranthesisGeneraion(output+')', n, c+1, o);
    }
}

int main(){

    ll n;
    cin >> n;
    string output = "";
    paranthesisGeneraion(output, n, 0, 0);

    return 0;
}