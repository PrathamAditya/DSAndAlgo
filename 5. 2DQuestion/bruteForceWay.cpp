/**
 * author: adityapratham
 **/
#include <bits/stdc++.h>

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

    // code

    for (int ti = 0; ti < m; ti++)
    {
        for (int tj = 0; tj < n; tj++)
        {
            for (int bi = ti; bi < m; bi++)
            {
                for (int bj = tj; bj < n; bj++)
                {
                    int sum = 0;
                    for (int i = ti; i <= bi; i++)
                    {

                        for (int j = tj; j <= bj; j++)
                        {
                            sum = sum + a[i][j];
                        }
                    }
                    cout << sum << '\n';
                }
            }
        }
    }

    return 0;
}