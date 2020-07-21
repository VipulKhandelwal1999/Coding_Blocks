#include <iostream>
#include <set>
using namespace std;


int main() {
    //1. Stores elements in sorted order
    // 2. Unique elements, each repeating element occurs only once
    set<int> s;
    s.insert(1);
    s.insert(5);
    s.insert(1);
    s.insert(5);
    s.insert(2);
    s.insert(3);

    for(int x:s){
       // cout<<x <<endl;
    }
    //Iterators are like pointers
    for(set<int>::iterator it = s.begin() ;it!=s.end();it++){
        cout<<(*it) <<endl;
    }

    return 0;
}
