#include<bits/stdc++.h>
using namespace std;

class person_compare {
public:
    bool operator()(pair<string,int> p1, pair<string, int>p2){
        return p1.second < p2.second;
    }
};

int main() {

    pair<string, int> p1 = make_pair("B", 100);
    pair<string, int> p2 = make_pair("A", 40);
    pair<string, int> p3 = make_pair("C", 80);
    pair<string, int> p4 = make_pair("D", 100);
    pair<string, int> p5 = make_pair("D", 90);

    //Multiset

    //Pair - Name(string), Money(int)

    //Custom Data Type
    multiset<pair<string, int>, person_compare> m;
    m.insert(p1);
    m.insert(p2);
    m.insert(p3);
    m.insert(p4);
    m.insert(p5);

    //It will be sorted lexographically according to first
    //If first is same then it will be sorted according to second
    for(auto p: m)
        cout << p.first << " " << p.second << endl;

    return 0;
}
