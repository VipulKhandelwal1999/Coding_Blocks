#include<bits/stdc++.h>
using namespace std;


//List is basically doubly linked list
int main(){

    list<int> l;

    //Init
    list<int>l1{1,2,30,4,5};

    //Differenr datatype
    list<string> l2{"apple", "mango", "guava", "grapes"};

    //Iterate over the list and print the data
    for(string s: l2){
        cout << s << "-->";
    }
    cout << endl;

    l2.push_back("pineapple");

    //Iterate over the list and print the data
    for(string s: l2){
        cout << s << "-->";
    }
    cout << endl;

    //sort
    l2.sort();

    //Iterate over the list and print the data
    for(string s: l2){
        cout << s << "-->";
    }
    cout << endl;

    //reverse
    l2.reverse();


    //pop_front
    cout << l2.front() << endl;
    l2.pop_front();
    cout << l2.front() << endl;

    //add to the front of the list
    l2.push_front("kiwi");
    cout << l2.back() << endl;
    l2.pop_back();

    //Iterate over the list and print the data
    for(auto it=l2.begin(); it!=l2.end(); it++){
        cout << (*it) << " -> ";
    }
    cout << endl;

    //Iterate over the list and print the data
    for(string s: l2){
        cout << s << "-->";
    }
    cout << endl;

    return 0;
}
