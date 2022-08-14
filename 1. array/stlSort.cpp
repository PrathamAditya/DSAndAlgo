#include <iostream>
#include <algorithm>

using namespace std;

// Defining the Comparator Function
bool compare(int a, int b)
{
    return a < b;
}

int main()
{
    int n;
    cout << "Enter n:";
    cin >> n;

    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << "Before sorting: "
         << "\n";
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }

    sort(a, a + n, compare);

    cout << "\n";
    cout << "After sorting: "
         << "\n";
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}
