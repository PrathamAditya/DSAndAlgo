#include <iostream>

using namespace std;

int main()
{
    int m, n;
    cout << "Enter m and n: ";
    cin >> m >> n;
    int a[m][n] = {0};

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }

    // sprialPrinting
    int startRow = 0;
    int startCol = 0;
    int endRow = m - 1;
    int endCol = n - 1;

    while (startRow <= endRow and startCol <= endCol)
    {
        // First
        for (int i = startCol; i <= endCol; i++)
        {
            cout << a[startRow][i] << " ";
        }
        startRow++;

        for (int i = startRow; i <= endRow; i++)
        {
            cout << a[i][endCol] << " ";
        }
        endCol--;

        for (int i = endCol; i >= startCol; i--)
        {
            cout << a[endRow][i] << " ";
        }
        endRow--;

        for (int i = endRow; i >= startRow; i--)
        {
            cout << a[i][startCol] << " ";
        }
        startCol++;
    }
}