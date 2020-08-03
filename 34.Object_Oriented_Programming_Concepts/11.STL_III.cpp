#include <iostream>
#include<cstring>
using namespace std;

//Let us define a Vector Class(User defined Vector)
class Vector{
    //Data Members and some functions
    int *arr;
    int cs;
    int maxSize;

public:
    Vector(int defaultSize=4){
        maxSize = defaultSize;
        cs = 0;
        arr = new int[maxSize];
    }
    void operator()(string s){
        cout<<s<<"is an awesome Place";
    }

    void push_back(int data){
        if(cs==maxSize){
            //Doubling Operations
            int *oldArr = arr;
            arr = new int[2*maxSize];
            maxSize = 2*maxSize;

            for(int i=0;i<cs;i++){
                arr[i] = oldArr[i];
            }
            //Delete the oldArr
            delete [] oldArr;
        }
        arr[cs] = data;
        cs++;
    }
    bool empty(){
        return cs==0;
    }
    int getSize(){
        return cs;
    }
    int getMaxSize(){
        return maxSize;
    }
    void pop_back(){
        if(!empty()){
            cs--;
        }
    }
    void print(){
        for(int i=0;i<cs;i++){
            cout<<arr[i]<<",";
        }
    }
    int at(int i){
        return arr[i];
    }
    //Operators over user defined [], (), +, * , - , ! etc
    //Box by reference
    int& operator[](int i){
        return arr[i];
    }
};

ostream& operator << (ostream &os, Vector v){
    cout<<"In << operator"<<endl;
    v.print();
    return os;
}
istream& operator>>(istream &is,Vector &v){
    //Input a vector

    return is;
}

int main() {
    Vector v(1000);
    //Operator () Call
    //v("Dehradun");

    Vector fun; //Default Copy Constructors - Shallow Copy
    //Looking like like a function, but it is an object [Functor : Functional Objects]
    //fun("Nainital");

    for(int i=0;i<=3;i++){
        v.push_back(i*i);
    }

    fun = v; // Copy Assignment Operators -> Shallow Copy

    cout<<v.getMaxSize()<<endl;
    v.push_back(7);
    cout<<v.getMaxSize()<<endl;
    v.print();

    //For Loop
    for(int i=0;i<v.getSize();i++){
      //  cout<<v[i]<<endl;
    }

    cout<<endl;
    cout<<v<<fun;

    v[2] = 8;
    v[2] /= 6;
    cout<<"FInal value" <<endl;
    cout<< v[2];



    return 0;
}
























