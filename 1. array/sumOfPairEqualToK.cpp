#include <iostream>

using namespace std;

int main()
{
    int n = 0;
    cout << "Enter the n: ";
    cin >> n;

    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << "\n";
    int k = 0;
    cout << "Enter the k: ";
    cin >> k;

    int i = 0;
    int j = n - 1;

    while (i <= j)
    {
        if (a[i] + a[j] == k)
        {
            cout << a[i] << " " << a[j];
            cout << "\n";
            i++;
            j--;
        }
        else if (a[i] + a[j] < k)
        {
            i++;
        }
        else
        {
            j++;
        }
    }
}