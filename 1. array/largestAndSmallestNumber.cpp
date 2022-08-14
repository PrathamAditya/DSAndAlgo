#include <iostream>
using namespace std;

int main()
{
    int sm = INT_MAX;
    int lg = INT_MIN;

    int n;
    cout << "Enter the n: ";
    cin >> n;

    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i] < sm)
        {
            sm = a[i];
        }
        if (a[i] > lg)
        {
            lg = a[i];
        }
    }
    cout << "Smallest: " << sm << "\n";
    cout << "Largest: " << lg << "\n";
}