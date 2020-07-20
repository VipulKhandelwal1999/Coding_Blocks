#include<bits/stdc++.h>
using namespace std;

//Copy Constructor - Make a copy of the given object
//It exists By Default

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
        // Constructor
        // Gets called automatically and only once.
        //Same name as class name
        //Constructor Overloading is happening here as we have different functions with same name
        Car(){
            cout << "Inside Constructor" << endl;
        }

        //Paramterised Constructor
        Car(float p, int m, char *n){
            price = p;
            model_no = m;
            strcpy(name, n);
        }

        Car(Car &x){

            price = x.price;
            model_no = x.model_no;
            strcpy(name, x.name);

        }

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

    //create an object
    Car c; //make a call to the constructor function present inside the class

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

    Car d(222, 111, "Audi");
    d.print();
    Car e(d); //copy constructor
    e.set_price(45);
    e.print();
    //another way of calling copy constructor
	Car f = e; //copy constructor
	f.print();

    return 0;
}
