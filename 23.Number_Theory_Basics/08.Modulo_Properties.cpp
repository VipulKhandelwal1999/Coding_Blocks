//Modulo Properties

#include<bits/stdc++.h>
using namespace std;

int main(){

    //Property 1:- (a+b)%m = ((a%m)+(b%m))%m
    //Property 2:- (a-b)%m = ((a%m)-(b%m)+m)%m
    //Property 3:- (a*b)%m = ((a%m)*(b%m))%m
    //Property 4:- (a/b)%m = ((a%m)*(b(inverse)%m))%m or ((a%m)*((b^-1)%m))%m
    //To calculate b inverse (it is basically multiplicative modulo inverse)
    //Example:- (6*y)%7 = 1 (So here y is basically modulo inverse of 6 w.r.t 7) Here y=6
    //Condition for modulo inverse to exist:- Modulo Inverse of N, under modulo p exists iff GCD(N,P) = 1 i.e.,coprime with each other
    /*
        To calculate modulo inverse we have two ways:-
        1.Using Fermatt's Little Theorom:-
            if GCD(a,m) = 1 then pow(a,(m-1))%m congruent to 1%m
            dividing both sides by a
            pow(a,m-2)%m = pow(a,-1)%m

            So to we just have to calculate pow(a,(m-2))
            (a/b)%m = ((a%m)*(b(inverse)%m))%m
            (a/b)%m = ((a%m)* (pow(b, m-2)%m))%m

        2.Using Extended Euclid's Algorithm
    */



    return 0;
}
