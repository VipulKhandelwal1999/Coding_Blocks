#include<bits/stdc++.h>
using namespace std;

int main(){

    int x = 10;
    cout << &x << endl;

    float y = 10.5;
    cout << &y << endl;

    //It doesn't work for character variables
    char ch = 'A';
    cout << &ch << endl; //It will print A

    //Explicit Typecasting from char* to void*
    cout << (void *)&ch << endl;

    return 0;
}
