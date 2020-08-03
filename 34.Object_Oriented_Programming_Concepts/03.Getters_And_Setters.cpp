#include<bits/stdc++.h>
using namespace std;

class Car {
    //Access specifiers - public and private
    //public:- If you want to give access to data members outside the class
    //private:- If you want to access inside the class
    //Changed access modifier of data members to public
    private:
        float price;

    public:
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

        void set_price(float p){
            if(p > 0)
                price = p;
        }

        float get_price(){
            return price;
        }
};

int main() {

    Car c;
    //private is basically access modifiers.
    //private means can't access data members outside.
    //By default all the data members are private
    // c.price = 100; // We cannot read or write private data members
    c.model_no = 112;
    c.name[0] = 'B';
    c.name[1] = 'M';
    c.name[2] = 'W';
    c.name[3] = '\0';

    cout << "Enter the discount you want to give: ";

    float discount;
    cin >> discount;

    c.set_price(100);

    cout << c.get_discounted_price(discount) << endl;
    c.apply_discount(discount);


    c.print();

    cout << c.get_price() << endl;
    return 0;
}
