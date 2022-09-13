#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{
    map<string, int> m;
    // insert
    m.insert(make_pair("Mango Shake", 120));

    pair<string, int> p;
    p.first = "Apple Juice";
    p.second = 150;
    m.insert(p);

    m["ok"] = 80;

    m["Lichi"] = 120;
    m["Grapes"] = 150;
    m["Shakshy"] = 120;

    // iterate over all the keys
    for (auto it = m.begin(); it != m.end(); it++)
    {
        cout << (*it).first << " : " << (*it).second << "\n";
    }

    // string fruit;
    // cin >> fruit;

    // auto it = m.find(fruit);
    // if (it != m.end())
    // {
    //     cout << "price of " << fruit << " is: " << m[fruit] << "\n";
    // }
    // else
    // {
    //     cout << "not there"
    //          << "\n";
    // }
}