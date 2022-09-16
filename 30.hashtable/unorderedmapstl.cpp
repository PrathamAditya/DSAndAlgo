#include <iostream>
#include <unordered_map>
#include <map>
#include <string>

using namespace std;

int main()
{
    unordered_map<string, int> m;
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

    for (auto it : m)
    {
        cout << it.first << " : " << it.second << "\n";
    }
}