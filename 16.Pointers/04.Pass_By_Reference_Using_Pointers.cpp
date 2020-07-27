#include<iostream>
using namespace std;

//Pass by Reference using Pointers
void increament(int *aptr){
    *aptr = *aptr + 1;
    cout << "Inside Function " << *aptr << endl;
}

int main() {

    int a = 10;
    increament(&a);
    cout << "Inside Main : " << a;

    return 0;

}
