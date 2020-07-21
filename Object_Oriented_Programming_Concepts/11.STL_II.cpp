#include <iostream>
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
    //Operators over user defined [], (), +, *, -, !, etc
    int& operator[](int i){
        return arr[i];
    }
};

/*
void operator << (ostream &os, Vector &v){
    cout << "In  << operator" << endl;
    v.print();
    return;
}
*/

//Operator Overloading is also called as functors or functional objects.
int main() {
    Vector v(1000);

    for(int i=0;i<=3;i++){
        v.push_back(i*i);
    }
    cout<<v.getMaxSize()<<endl;
    v.push_back(7);
    cout<<v.getMaxSize()<<endl;
    v.print();
    cout << endl;
    cout << v[1];

    // cout << v;

    return 0;
}
