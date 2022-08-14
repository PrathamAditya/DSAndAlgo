#include <iostream>

using namespace std;

int main()
{
    // Init of array
    int a[10];

    // size ofArray
    cout << sizeof(a) << "\n";
    // Input from the user
    for (int i = 0; i < 5; i++)
    {
        cin >> a[i];
    }
    // Print the all the elements

    for (int i = 0; i < 10; i++)
    {
        cout << a[i] << ", ";
    }
}
