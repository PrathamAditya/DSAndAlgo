#include <iostream>
#include "hashtable.h"

using namespace std;
int main()
{
    Hashtable<int> price_menu;
    price_menu.insert("Burger", 120);
    price_menu.insert("Pepsi", 20);
    price_menu.insert("Bantaa", 15);
    price_menu.insert("Indo Tandoori Pizza", 775);
    price_menu.print();
    cout << "\n";
    price_menu["Dosa"] = 60;
    price_menu["Dosa"] += 10;
    cout << price_menu["Dosa"] << "\n";
    price_menu.print();
    cout << "\n";
}