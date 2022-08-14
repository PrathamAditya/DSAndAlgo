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
void mergeSort(int A[], int n, int s, int e)
{
    // base case
    if (s >= e)
    {
        return;
    }

    // rec case
    // Divide
    int mid = (s + e) / 2;

    // recursively
    mergeSort(A, n, e, mid);
    mergeSort(A, n, mid + 1, e);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    return 0;
}