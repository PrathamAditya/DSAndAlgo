/**
 * author: adityapratham
 **/
#include <bits/stdc++.h>

using namespace std;

int main()
{
    // Allocation
    int b[100];
    cout << sizeof(b) << "\n";

    // Dynamic Allocation
    int n;
    cin >> n;
    int *a;
    a = new int[n];
    cout << sizeof(a) << "\n";

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {

        cout << a[i] << " ";
    }
    delete[] a;
    return 0;
}