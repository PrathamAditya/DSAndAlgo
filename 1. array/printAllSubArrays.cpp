#include <iostream>
using namespace std;

void GenerateSubA(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            for (int k = i; k <= j; k++)
            {
                cout << a[k] << " , ";
            }
            cout << "\n";
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
    cout << "\n";
    cout << "SubArrays: "
         << "\n";
    GenerateSubA(a, n);
}
