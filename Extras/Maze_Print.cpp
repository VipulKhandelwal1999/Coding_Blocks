#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll maze(ll startx, ll starty, ll endx, ll endy, string osf){

    //base case
    if(startx > endx || starty > endy) 
        return 0;
    if(startx==endx && starty==endy){
        cout << osf << "\n";
        return 1;
    }
    
    //recursive task
    ll right = maze(startx, starty+1, endx, endy, osf+'R');
    ll down = maze(startx+1, starty, endx, endy, osf+'D');

    //self work
    return right + down;
}

int main(){
    cout << "Number Of Ways: " << maze(0,0,1,2, "") << "\n";
    return 0;
}