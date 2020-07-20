#include<bits/stdc++.h>
using namespace std;

int power(int x, int y){
    if(y==0)
        return 1;
    return x*power(x,y-1);
}

int main(){
    cout << power(4,3);
    return 0;
}
