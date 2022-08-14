/**
 * author: adityapratham
 **/
#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long int
using namespace std;

ll fun(int n)
{
    if (n < 4)
    {
        return 1;
    }
    else if (n == 4)
    {
        return 2;
    }
    else
    {
        return fun(n - 1) + fun(n - 4);
    }
}

int main()
{
    ll tt;
    cin >> tt;

    while (tt--)
    {
        /* code */
        ll n;
        cin >> n;

        cout << "Ans: " << fun(n) << "\n";
    }

    return 0;
}