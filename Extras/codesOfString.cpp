#include<bits/stdc++.h>
using namespace std;
#define ll long long

void codesOfString(string str, string osf, char *mapping){
    if(str.size() == 0){
        cout << osf << endl;
        return;
    }
    ll firstNumber = str[0] - '0';
    if(str.size() >= 2){
        ll secondNumber = stol(str.substr(0,2));
        if(secondNumber<=26){
            codesOfString(str.substr(2), osf+mapping[secondNumber], mapping);
        }
        codesOfString(str.substr(1), osf+mapping[firstNumber], mapping);
    }
    else{
        codesOfString(str.substr(1), osf+mapping[firstNumber], mapping);
    }
}

int main(){
    char mapping[27] = {'#', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k' , 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    codesOfString("123", "", mapping);

    return 0;
}