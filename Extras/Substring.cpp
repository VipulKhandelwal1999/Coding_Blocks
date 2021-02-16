#include<bits/stdc++.h>
using namespace std;
#define ll long long

void codesOfString(string str, string osf){
    if(str.size() == 0){
        cout << osf << endl;
        return;
    }
    codesOfString(str.substr(1), osf+str[0]);
    codesOfString(str.substr(1), osf);
}

int main(){
    codesOfString("abc", "");

    return 0;
}