#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll maze(ll startx, ll starty, ll endx, ll endy){

    //base case
    if(startx > endx || starty > endy) 
        return 0;
    if(startx==endx && starty==endy){
        return 1;
    }
    
    //recursive task
    ll right = maze(startx, starty+1, endx, endy);
    ll down = maze(startx+1, starty, endx, endy);

    //self work
    return right + down;
}

int main(){
    cout << maze(0,0,1,2);
    return 0;
}