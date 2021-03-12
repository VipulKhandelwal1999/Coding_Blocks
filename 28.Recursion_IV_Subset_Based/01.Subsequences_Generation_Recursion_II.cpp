#include<bits/stdc++.h>
using namespace std;

void generate_subsequence(string in, string &out, int i){
    //base case
    if(i==in.size()){
        cout << out << "\n";
        return;
    }

    // rec case
    // include the current char
    out += in[i];
    generate_subsequence(in, out, i+1);
    out.pop_back();
    //exclude the current char
    generate_subsequence(in, out, i+1);
}

int main(){

    string input = "abc";
    string output;
    generate_subsequence(input, output, 0);

    return 0;
}