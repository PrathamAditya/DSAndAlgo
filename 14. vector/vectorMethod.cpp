#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
    vector<int> d{1, 2, 3, 4, 5};
    // O(1) - most of the time
    d.push_back(16);

    // O(1)
    d.pop_back();

    // Insert in the middle
    d.insert(d.begin() + 3, 4, 100);

    for (int x : d)
    {
        cout << x << " ";
    }
    cout << "\n";

    // Reserve
    vector<int> v2{1, 2, 3, 4, 5};
    v2.reserve(1000);
    int tt = 1;

    for (auto it = 0; it != 3; it++)
    {
        v2.push_back(tt);
        tt++;
        cout << v2.capacity() << "\n";
    }

    return 0;
}
