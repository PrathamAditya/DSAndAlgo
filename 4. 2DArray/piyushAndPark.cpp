/**
 * author: adityapratham
 **/
#include <bits/stdc++.h>

using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, M, K, S;
    cin >> N >> M >> K >> S;
    int row = N;
    int col = M;

    char a[N][M];
    bool success = true;

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; i < col; i++)
        {
            if (S < K)
            {
                success = 0;
                break;
            }

            if (a[i][j] == '*')
            {
                S = S + 5;
            }
            else if (a[i][j] == '.')
            {
                S = S - 2;
            }
            else
            {
                break;
            }

            // execpt for the last column
            if (j != col - 1)
            {
                S--;
            }
        }
    }

    if (success)
    {
        cout << "YES"
             << "\n";
        cout << S << "\n";
    }
    else
    {
        cout << "NO"
             << "\n";
    }

    return 0;
}