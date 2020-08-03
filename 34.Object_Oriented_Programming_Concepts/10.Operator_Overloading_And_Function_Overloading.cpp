#include<bits/stdc++.h>
using namespace std;

//Function Overloading: Same function name but accept different no. of parameters in each
//Operator Overloading:

class Complex{

    int real;
    int img;

    public:

        Complex(){
            real = 0;
            img = 0;
        }

        //Parameterised Constructor
        Complex(int r, int i){
            real = r;
            img = i;
        }

        //Copy Constructor
        //It exists bydefault
        void setReal(const int r){
            real = r;
        }

        void setImg(const int i){
            img = i;
        }

        int getReal() const{
            return real;
        }

        int getImg() const{
            return img;
        }

        void print(){
            if(img>0)
                cout << real << " + " << img << "i" << endl;
            else
                cout << real << " - " << -img << "i" << endl;
        }
        void add(const Complex &x){
            real += x.real;
            img += x.img;
        }

        void operator+(const Complex &x){
            real += x.real;
            img += x.img;
        }

        void operator!(){
            img *= -1;
        }

        void operator[](string s){
            cout << real << " + " << img << s << endl;
        }

};

/*
void operator>>(istream& is, Complex &c){
            int r1, i1;
            is>>r1>>i1;
            c.setReal(r1);
            c.setImg(i1);
        }

void operator<<(ostream& os, Complex &c){
        c.print();
    }
*/
istream& operator>>(istream& is, Complex &c){
            int r1, i1;
            is>>r1>>i1;
            c.setReal(r1);
            c.setImg(i1);
            return is;
        }

ostream& operator<<(ostream& os, Complex &c){
        c.print();
        return os;
    }

int main(){

    Complex c1(5, 3);
    Complex c2;
    c2.setImg(4);
    c2.setReal(1);

    c1.print();
    c2.print();

    //c1.add(c2);
    c1 + c2;
    c1.print();
    c2.print();

    c1[" is cool "];

    // << , >>
    Complex d, e;
    cin>>d>>e;
    cout<<d<<e;

    return 0;
}
