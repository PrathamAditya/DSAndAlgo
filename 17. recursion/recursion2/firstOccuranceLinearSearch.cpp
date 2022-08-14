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
//     if (i == n)
//     {
//         return -1;
//     }
//     else if (A[i] == key)
//     {
//         return i;
//     }
//     else
//     {
//         fun(A, i + 1, n, key);
//     }
// }

int fun(int A[], int n, int key)
{
    int x;
    if (n == 0)
    {
        return -1;
    }

    // rec case

    if (A[0] == key)
    {
        return 0;
    }
    else
    {
        x = fun(A + 1, n - 1, key);
    }
    if (x == -1)
        return -1;
    return x + 1;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int A[] = {1, 2, 3, 4, 5, 5, 6, 7, 8};
    int n = 9;

    cout << fun(A, n, 1);

    return 0;
}