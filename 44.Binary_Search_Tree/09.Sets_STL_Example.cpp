#include<bits/stdc++.h>
using namespace std;

//Pairs will be sorted based upon their first value


int main() {

    set<pair<int, int>> s;
    s.insert(make_pair(10,1));
    s.insert(make_pair(10,5));
    s.insert(make_pair(20,1));
    s.insert(make_pair(20,100));
    s.insert(make_pair(5,1));
    s.insert(make_pair(5,3));
    s.insert(make_pair(5,3));
    s.insert(make_pair(10,6));

    s.erase(s.find(make_pair(5,3)));

    auto it = s.lower_bound(make_pair(20, 1));
    cout << it->first << "," << it->second << endl;

    auto it2 = s.upper_bound(make_pair(10, 6));
    cout << it2->first << "," << it2->second << endl;

    //If we find out upper bound in which key is greater than this key
    auto it3 = s.upper_bound(make_pair(10, INT_MAX));
    cout << it3->first << "," << it3->second << endl;

    for(auto p: s)
        cout << p.first << " " << p.second << endl;

    return 0;
}
