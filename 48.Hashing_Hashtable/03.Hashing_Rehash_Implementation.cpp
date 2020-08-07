#include<iostream>
#include<bits/stdc++.h>
#include "01.Hashtable.h"
using namespace std;

int main() {

    Hashtable<int> price_menu;

    price_menu.insert("Burger", 120);
    price_menu.insert("Pepsi", 200);
    price_menu.insert("Cola", 20);
    price_menu.insert("Pizza", 720);
    price_menu.insert("Nachos", 620);
    price_menu.insert("Pasta", 110);
    price_menu.insert("Margerita", 900);
    price_menu.print();

    return 0;
}
