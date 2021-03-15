#include<bits/stdc++.h>
using namespace std;

void generate_strings(string in, string out, int i){

    //base case
    if(i==in.size()){
        cout << out << endl;
        return;
    }

    //rec case
    //one digit at a time
    int digit = in[i] - '0';
    char ch = digit + 'A' - 1;
    generate_strings(in, out + ch, i+1);

    //two digit at a time
    if(i+1 != in.size()){
        int secondDigit = in[i+1] - '0';
        int no = digit*10 + secondDigit;
        if(no <= 26){
            ch = no + 'A' - 1;
            generate_strings(in, out + ch, i+2);
        }
    }
    return;

}

int main() {

    string str;
    cin >> str;
    string out;
    generate_strings(str, out, 0);

    return 0;
}