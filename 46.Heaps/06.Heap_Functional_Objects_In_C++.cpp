#include<bits/stdc++.h>
using namespace std;

class Fun {
    public:
        void operator()(string s){
            cout << "Having Fun Inside Operator() fn" << s << endl;
        }
};

int main() {

    Fun f; //Constructor
    f("C++"); //Overloaded () Operator = Function call where f is an object
    //Its an object but behaving like a functional call so it is knwon as functor

    return 0;
}
