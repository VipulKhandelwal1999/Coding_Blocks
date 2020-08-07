//Sets
//Stores Unique Elements Only
//Insertion + Deletion (O(logn))
//Uses BST/Red Black Tree internally
//Sets Store Elements In Sorted Order Ascending
//Unordered Sets Store Elements In Random Order
//We can't Update Values In Set
//If we want to modify something then we have to insert that element and delete modify element

#include<bits/stdc++.h>
using namespace std;

int main() {

    int arr[] = {10, 20, 11, 9, 8, 11, 10};
    int n = sizeof(arr)/sizeof(int);

    set<int> s;
    for(int i=0; i<n; i++){
        s.insert(arr[i]);
    }

    //To delete element
    s.erase(10);
    //OR
    auto it = s.find(10);
    s.erase(10);

    //Print all the elements
    for(auto it = s.begin(); it!=s.end(); it++){
        cout << *(it) << ", ";
    }

    return 0;
}
