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
int main()
{

    ios::sync_with_stdio(0);
    cin.tie(0);
    const int a = 90;
    int *b = new int;
    *b = 2;
    b = (int *)&a;
    cout << *b << "\n";
    return 0;
}