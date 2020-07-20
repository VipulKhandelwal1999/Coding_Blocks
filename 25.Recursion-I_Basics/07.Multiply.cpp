#include<bits/stdc++.h>
using namespace std;

int multiply(int x, int y){
    if(y==0)
        return 0;

    return x + multiply(x, y-1);
}

int main(){
    cout << multiply(5,4);
    return 0;
}
