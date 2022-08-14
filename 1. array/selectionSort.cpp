#include <bits/stdc++.h>

using namespace std;

void SelectionSort(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int x = INT_MAX;
        int point = -1;
        for (int j = i + 1; j < n; j++)
        {

            if (x > a[j])
            {
                x = a[j];
                point = j;
            }
        }
        if (a[i] > x)
        {
            swap(a[i], a[point]);
        }
    }
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
    SelectionSort(a, n);
    cout << "\n";
    cout << "After sorting: "
         << "\n";
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}