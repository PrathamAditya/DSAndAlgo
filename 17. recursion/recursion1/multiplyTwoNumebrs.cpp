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

int fun(int a, int b)
{
    if (b == 1)
    {
        return a;
    }
    return a + fun(a, b - 1);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, p;
    cin >> n >> p;

    cout << "Multipaction: " << n << " " << p << ": " << fun(n, p) << "\n";
    return 0;
}