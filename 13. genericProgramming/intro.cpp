#include <iostream>

using namespace std;

template <class T>

int search(T arr[], int n, T key)
{
    bool t = true;
    for (int i = 0; i < n; i++)
    {
        /* code */
        if (arr[i] == key)
        {
            return i;
        }
    }
    return n;
}

int main()
{
    // int a[] = {1, 2, 3, 4, 5};
    // int n = sizeof(a) / sizeof(a[0]);
    // int key = 1;

    // cout << search(a, n, key);

    char a[] = {'a', 'b', 'c', 'd', 'e'};
    int n = sizeof(a) / sizeof(a[0]);
    char key = 'c';
    cout << search(a, n, key);

    return 0;
}