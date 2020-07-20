#include<bits/stdc++.h>
using namespace std;

void spell(int n){
    if(n == 0)
        return;
    spell(n/10);
    // After the function call
    //Bottom Up
    int digit = n%10;
    switch(digit){
        case 0:
            cout << "Zero ";
            break;
        case 1:
            cout << "One ";
            break;
        case 2:
            cout << "Two ";
            break;
        case 3:
            cout << "Three ";
            break;
        case 4:
            cout << "Four ";
            break;
        case 5:
            cout << "Five ";
            break;
        case 6:
            cout << "Six ";
            break;
        case 7:
            cout << "Six ";
            break;
        case 8:
            cout << "Six ";
            break;
        case 9:
            cout << "Six ";
            break;
    }
}

int main(){

    int n;
    cin >> n;
    spell(n);
    return 0;
}
