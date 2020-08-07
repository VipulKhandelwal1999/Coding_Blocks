#include<bits/stdc++.h>
using namespace std;

int main() {

    unordered_map<string, vector<string>> phonebook;
    phonebook["rahul"].push_back("9110");
    phonebook["rahul"].push_back("9120");
    phonebook["rahul"].push_back("9130");
    phonebook["kajal"].push_back("9210");
    phonebook["kajal"].push_back("9710");
    phonebook["kajal"].push_back("9610");

    for(auto p:phonebook){
        cout << "Name" << p.first << " -> ";
        for(string s:p.second){
            cout << s << ",";
        }
        cout << endl;
    }

    string name;
    cin >> name;

    if(phonebook.count(name) == 0){
        cout << "Absent ";
    }
    else{
        for(string s: phonebook[name]){
            cout << s << endl;
        }
    }

    return 0;
}
