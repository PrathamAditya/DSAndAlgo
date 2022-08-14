/**
 * author: adityapratham
 **/
#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long int
using namespace std;

#ifdef LOCAL
#else
#endif

// int fun(int A[], int i, int n, int key)
// {
//     if (n - 1 == 0)
//         return -1;

//     if (A[n - 1] == key)
//     {
//         return n - 1;
//     }
//     return fun(A, i, n - 1, key);
// }

int fun(int A[], int n, int key)
{
    if (n == 0)
    {
        return -1;
    }

    int x = fun(A + 1, n - 1, key);
    if (x == -1)
    {
        if (A[0] == key)
        {
            return 0;
        }
        else
        {
            return -1;
        }
    }
    return x + 1;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int A[] = {1, 2, 3, 4, 5, 5, 6, 6, 6, 6, 7, 8, 8};
    int n = sizeof(A) / sizeof(A[0]);

    cout << fun(A, n, 100);

    return 0;
}