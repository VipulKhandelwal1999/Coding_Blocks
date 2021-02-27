#include <iostream>
#include <cstring>
using namespace std;

// To convert string to character array
//     // assigning value to string s
//     string s = "geeksforgeeks";
 
//     int n = s.length();
 
//     // declaring character array
//     char char_array[n + 1];
 
//     // copying the contents of the
//     // string to char array
//     strcpy(char_array, s.c_str());
 
//     for (int i = 0; i < n; i++)
//         cout << char_array[i];
 

//char *strtok(char *s,char *delimiters)
// returns a token on each subsequent call
// on the first call function should be passed with string argument for 's'
// on subsequent calls we should pass the string argument as null

int main() {
    
    char s[100] = "Today, is a rainy, day";  

    char *ptr = strtok(s," ");
    cout<<ptr<<endl;

    while(ptr!=NULL){
        ptr = strtok(NULL," ");
        cout<<ptr<<endl;
    }
    return 0;
}
