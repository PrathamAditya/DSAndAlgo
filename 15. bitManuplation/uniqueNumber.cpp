#include <iostream>

using namespace std;

int main()
{
    int a[] = {3, 2, 3, 5, 6, 5, 2};
    int n = sizeof(a) / sizeof(a[0]);
    int op;

    for (int i = 0; i < n; i++)
    {
        op = op ^ a[i];
    }
    cout << op << "\n";
}