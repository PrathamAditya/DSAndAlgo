#include <iostream>
using namespace std;

int main()
{
    cout << "Enter the number of elements: ";
    int n;
    cin >> n;

    int a[n] = {0};
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    cout << "Enter the Key: ";
    int key;
    cin >> key;

    bool isBool = 1;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == key)
        {
            cout << "Key is found at: " << i << "\n";
            isBool = 0;
            break;
        }
    }
    if (isBool)
    {
        cout << "The key is not present"
             << "\n";
    }
}