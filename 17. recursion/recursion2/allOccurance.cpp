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
// void fun(int A[], int n, int key)
// {
//     if (n == 0)
//         return;

//     if (A[0] ==)
// }
bool is = 1;

void fun(int A[], int i, int n, int key)
{

    if (i == n)
    {
        if (is)
        {
            cout << -1;
        }

        return;
    }

    if (A[i] == key)
    {
        is = 0;
        cout << i << " ";
    }
    fun(A, i + 1, n, key);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int A[] = {1, 2, 3, 4, 5, 5, 6, 6, 6, 6, 7, 8, 8};
    int n = sizeof(A) / sizeof(A[0]);

    fun(A, 0, n, 100);
    cout << "\n";
    fun(A, 0, n, 6);
    return 0;
}