#include<bits/stdc++.h>
using namespace std;

//Compute a^n
//Approach-I
int power(int a, int n){

    // Base Case
    if(n == 0)
        return 1;
    //Recursive Case
    return a*power(a, n-1);
}
// Approach-II
int fast_power(int a, int n){

    if(n == 0)
        return 1;

    // rec_case
    int small_ans = fast_power(a, n/2);
    small_ans *= small_ans;

    //Don't do return fast_power(a, n/2)*fast_power(a, n/2) because in this we are making 2 recursive calls which is inefficient.
    if(n&1){
        return small_ans*a;
    }

    return small_ans;
}


int main(){
    cout << power(2, 5);
    return 0;
}
