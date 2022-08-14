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
    int row = m;
    int col = n;
    for (int i = 0; i < col; i++)
    {
        if (i % 2 == 0)
        {
            for (int j = 0; j < row; j++)
            {
                cout << a[j][i] << " ";
            }
        }
        else
        {
            for (int j = row - 1; j >= 0; j--)
            {
                cout << a[j][i] << " ";
            }
        }

        cout << "\n";
    }
    return 0;
}