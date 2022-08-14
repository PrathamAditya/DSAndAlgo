/**
 * author: adityapratham
 **/
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n = 0;
    int m = 0;
    cin >> m >> n;
    int a[m][n];

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }

    int key;
    cout << "Enter the key: ";
    cin >> key;

    // SCS
    int row = 0;
    int col = n - 1;

    bool good = 1;

    while (0 <= row < m && 0 <= col < n)
    {
        cout << row << " " << col << "\n";
        if (row < 0 || col < 0)
        {
            break;
        }
        if (a[row][col] > key)
        {
            col--;
        }
        else if (a[row][col] < key)
        {
            row++;
        }
        else
        {
            cout << "Found: ";
            cout << row << " " << col;
            good = 0;
            break;
        }
    }
    if (good)
    {
        cout << "Not in the martix (.";
    }

    return 0;
}