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

void fun(int &a, int &b)
{
    int c;
    c = a;
    cout << c << "\n";
    a = b;
    b = c;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a = 10;
    int b = 20;
    cout << &a << " " << &b;
    cout << "\n";
    fun(a, b);

    cout << &a << " " << &b;
    return 0;
}