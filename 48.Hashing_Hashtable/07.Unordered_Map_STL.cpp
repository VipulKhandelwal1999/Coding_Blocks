/*
Unordered Map - Hashtable
Best Thing (On an average)
Insertion - O(1)
Erase - O(1)
Find - O(1)
We are saying on an average because as the table size grows bigger
Rehashing will be done which will take O(n) time to copy all elements
from old table to new table.
Inserts in random order
*/

#include<bits/stdc++.h>
using namespace std;

int main() {

    unordered_map<string, int> m;

    //1. Insert
    m.insert(make_pair("Mango", 100));
    pair<string, int> p;
    p.first = "Apple";
    p.second = 120;

    m.insert(p);

    m["Banana"] = 20;

    //2. Search
    string fruit;
    cin >> fruit;

    //find return iterator
    auto it = m.find(fruit);
    if(it != m.end()){
        cout << "Price of " << fruit << " is " << m[fruit] << endl;
    }
    else{
        cout << "Fruit is not present" << endl;
    }

    //Another way to find a particular map
    //It stores unique keys only once
    //count returns integer 1(if present) or 0(if not)
    if(m.count(fruit)){
        cout << "Price is " << m[fruit] << endl;
    }
    else{
        cout << "Couldn't find" << endl;
    }

    //3.Erase
    m.erase(fruit);

    if(m.count(fruit)){
        cout << "Price is " << m[fruit] << endl;
    }
    else{
        cout << "Couldn't find" << endl;
    }

    //4.Update
    m[fruit] = 20;
    m[fruit] += 20;
    if(m.count(fruit)){
        cout << "Price is " << m[fruit] << endl;
    }
    else{
        cout << "Couldn't find" << endl;
    }

    m["litchi"] = 60;
    m["pineapple"] = 80;

    //Iterate over all the key value pairs
    for(auto it=m.begin(); it!=m.end(); it++){

        cout << it->first << " " << it->second << endl;
    }
    //for each loop
    for(auto p:m){
        cout << p.first << " : " << p.second << endl;
    }

    return 0;
}
