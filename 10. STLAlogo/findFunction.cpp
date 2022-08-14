#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int n = 5;

    int key;
    cin >> key;

    auto it = find(arr, arr + 5, key);
    cout << it - arr << "\n";
}