//Multiset - That can store multiple elements that have same value
//Stored in a specific order -> sorted according to internal comparison object
//Values Once Inserted can't be modified
//Associative container -> elements are referred by their value not by the index
//underlying data structure -> BST

#include<bits/stdc++.h>
using namespace std;
typedef multiset<int>::iterator It;


int main() {

    int arr[] = {10, 20, 30, 20, 30, 30, 30, 10, 30};
    int n = sizeof(arr)/sizeof(arr[0]);

    multiset<int> m(arr, arr+n);

    //earse - 20
    m.erase(20);

    //insert 80
    m.insert(80);

    //Iterate
    for(int x: m)
        cout << x << ", ";
    cout << endl;

    //count
    cout << "Count " << m.count(10) << endl;

    //find
    auto it = m.find(30);
    cout << (*it) << endl;

    //Get all elements which are equal to 30
    pair<It, It> range = m.equal_range(30);

    for(auto it=range.first; it!=range.second; it++)
        cout << *it << " ";
    cout << endl;

    //lower bound >= and upper bound >
    for(auto it=m.lower_bound(10); it!=m.upper_bound(77); ++it)
        cout << *it << " ";
    cout << endl;

    return 0;
}
