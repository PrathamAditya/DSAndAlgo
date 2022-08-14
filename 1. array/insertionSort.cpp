#include <iostream>

using namespace std;
void Selectionsort(int a[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int e = a[i];
        int j = i - 1;
        while (j >= 0 and e > a[j])
        {
            a[j + 1] = a[j];
            j--;
            a[j + 1] = e;
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
    Selectionsort(a, n);
    cout << "\n";
    cout << "After sorting: "
         << "\n";
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}