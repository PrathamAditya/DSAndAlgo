#include <iostream>
#include <vector>
using namespace std;
int main(int argc, char const *argv[])
{
    /* code */
    vector<int> v(5, 10);
    vector<int> v2(v);

    // iterate over the vector
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << "\n";

    for (auto it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }
    cout << "\n";

    for (int x : v)
    {
        cout << x << " ";
    }
    cout << "\n";

    vector<int> v3;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int no;
        cin >> no;
        v3.push_back(no);
    }
    // Understand st memeory level , what are diff
    cout << v.size() << "\n";
    cout << v.capacity() << "\n"; // size of underlying array
    cout << v.max_size() << "\n"; // avaible mem to expand

    cout << v3.size() << "\n";
    cout << v3.capacity() << "\n"; // size of underlying array
    cout << v3.max_size() << "\n"; // avaible mem to expand
    return 0;
}
