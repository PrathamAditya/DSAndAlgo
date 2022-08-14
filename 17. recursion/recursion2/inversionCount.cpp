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
int x = 0;

void fun(int A[], int i, int j, int n)
{
    if (i > n - 2)
    {
        return;
    }
    if (A[i] > A[j])
    {
        x++;
    }
    else
    {
        fun(A, i, j + 1, n);
    }
    fun(A, i + 1, i + 2, n);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int A[] = {1, 5, 2, 6, 3, 0};
    int n = sizeof(A) / sizeof(A[0]);
    fun(A, 0, 1, n);

    cout << x << "\n";
    return 0;
}