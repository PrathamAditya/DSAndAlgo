
#include <bits/stdc++.h>

using namespace std;

// void rotateImage(int a[][1000], int n)
// {
//     // Rotating rows
//     for (int i = 0; i < n; i++)
//     {
//         int start = 0;
//         int end = n - 1;
//         while (start <= end)
//         {
//             swap(a[i][start], a[i][end]);
//             start++;
//             end--;
//         }
//     }

//     // Transpose
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < n; j++)
//         {
//             if (i < j)
//             {
//                 swap(a[i][j], a[j][i]);
//             }
//         }
//     }
// }

int main()
{
    int n = 0;
    cin >> n;
    int a[n][n];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }

    // Reverse Method
    for (int i = 0; i < n; i++)
    {
        int start = 0;
        int end = n - 1;
        while (start <= end)
        {
            swap(a[i][start], a[i][end]);
            start++;
            end--;
        }
    }

    // Transpose
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i < j)
            {
                swap(a[i][j], a[j][i]);
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}