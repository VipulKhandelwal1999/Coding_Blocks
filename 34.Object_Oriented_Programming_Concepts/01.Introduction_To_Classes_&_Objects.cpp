//Procedural Programming (Functions)
/*-----------------------------------*/
//Object Oriented Programming (OOPS) --> C++
/*-----------------------------------*/
//Real World Entities => Objects In Program
/*-----------------------------------*/
#include<bits/stdc++.h>
using namespace std;

// Its equivalent to defining a new datatype
class Car {
    int price;
    int model_no;
    char name[20];
};

int main() {

    //create an object
    Car c;
    // Always Remember class is not occupying any memory.It's simply Blueprint
    // The memory is occupied by object.Here it is c.

    cout << sizeof(c) << endl;
    cout << sizeof(Car) << endl;

    return 0;
}
