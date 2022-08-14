#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int arr[] = {20, 30, 40, 40, 40, 50, 100, 1000};
    int n = 6;

    int key;
    cin >> key;

    // search in sorted array

    bool present = binary_search(arr, arr + n, key);

    if (present)
    {
        cout << "Present"
             << "\n";
    }
    else
    {
        cout << "Not Present"
             << "\n";
    }

    // index of the element

    auto it = lower_bound(arr, arr + n, 50);

    cout << "Lower bound of 40 is: " << (it - arr) << "\n";

    auto it2 = upper_bound(arr, arr + n, 50);

    cout << "Upper bound of 40 is: " << (it2 - arr) << "\n";

    cout << "Frequeny of 40: " << it2 - it << "\n";
}