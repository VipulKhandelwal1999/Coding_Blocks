#include<bits/stdc++.h>
using namespace std;

int main() {

    //Allocation + Deallocation = Compiler
    int b[100] = {0};
    cout << sizeof(b) << endl;
    cout << b << endl; //symbol table
    //here b cant be overwritten, b is a part of Read Only memory

    //Dynamic Allocation (on the fly)
    int n;
    cin >> n;
    int *a = new int[n]{0};
    cout << sizeof(a) << endl;
    cout << a << endl; //variable a that is created inside the static memory
    // a = new char[30];

    //No change
    for(int i=0; i<n; i++){
        cin >> a[i];
        cout << a[i] << " ";
    }
    //Freeup the space
        delete [] a;

    return 0;
}
