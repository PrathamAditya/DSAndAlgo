/**
 * author: adityapratham
 **/
#include <bits/stdc++.h>

using namespace std;

// void BS(int l, int h, int a[], int key)
// {
//     int mid = (h + l) / 2;
//     if (mid == l && a[mid] != key)
//     {
//         cout << "Element is not there"
//              << "\n";
//     }
//     else if (a[mid] == key)
//     {
//         cout << "Index: " << mid;
//     }
//     else if (key < a[mid])
//     {
//         h = mid - 1;
//         BS(l, h, a, key);
//     }
//     else
//     {
//         l = h + 1;
//         BS(l, h, a, key);
//     }
// }
int BS(int l, int h, int a[], int key)
{

    while (l <= h)
    {
        int mid = (l + h) / 2;
        if (a[mid] == key)
        {
            return mid;
        }
        else if (a[mid] > key)
        {
            h = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    return -1;
}

int main()
{
    int n;
    cout << "Enter n: ";
    cin >> n;

    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int key;
    cout << "Enter the key: ";
    cin >> key;
    cout << BS(0, n - 1, a, key);

    return 0;
}