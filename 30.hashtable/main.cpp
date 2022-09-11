#include <iostream>
#include "hashtable.h"

using namespace std;
int main()
{
    Hashtable<int> price_menu;
    price_menu.insert("Burger", 120);
    // price_menu.insert("Pepsi", 20);
    // price_menu.insert("Bantaa", 15);
    // price_menu.insert("Indo Tandoori Pizza", 775);
    // price_menu.insert("Coke", 30);
    // // cout << price_menu.getLF();
    // // cout << "\n";
    // price_menu.insert("Coke(yeah that one)", 5000);
    // // cout << price_menu.getLF();
    // // cout << "\n";

    price_menu.print();
    cout << price_menu.getLF();
    cout << "\n";
}