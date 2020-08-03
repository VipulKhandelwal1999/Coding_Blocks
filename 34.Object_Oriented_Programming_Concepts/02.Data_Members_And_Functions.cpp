#include<bits/stdc++.h>
using namespace std;

class Car {
    //Changed access modifier of data members to public
    public:
        float price;
        int model_no;
        char name[20];

        //Methods (Functions in Procedural Programming)
        float get_discounted_price(float x){
            return price*(1.0 - x);
        }

        void apply_discount(float x){
            price = price*(1.0 - x);
        }

        void print(){
            cout << "Name " << name << endl;
            cout << "Model No " << model_no << endl;
            cout << "Price " << price << endl;
        }


};

int main() {

    Car c;
    //private is basically access modifiers.
    //private means can't access data members outside.
    //By default all the data members are private
    c.price = 100;
    c.model_no = 112;
    c.name[0] = 'B';
    c.name[1] = 'M';
    c.name[2] = 'W';
    c.name[3] = '\0';

    cout << "Price: " << c.price << " Model No: " << c.model_no << " Company: " << c.name << endl;
    cout << "Enter the discount you want to give: ";

    float discount;
    cin >> discount;

    cout << c.get_discounted_price(discount) << endl;
    c.apply_discount(discount);
    c.print();

    //We can also define multiple objects and each will have same function prototype i.e., they reside in common memory and data members reside in different memory
    Car d, e;

    return 0;
}
