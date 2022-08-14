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

void inc(int &a)
{
    a = a + 1;
    cout << "Inside Function: " << a << endl;
}
int main()
{
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    // // Address of operator
    // int x = 10;
    // cout << &x << "\n";

    // char ch = 'A';
    // cout << (void *)&ch << "\n";

    // pointers

    // int x = 10;
    // int *xptr;
    // xptr = &x;

    // cout << &x << "\n";
    // cout << xptr << "\n";

    // Derefrancing
    // int x = 10;
    // int *xptr = &x;

    // cout << *xptr << "\n";

    // Pass by refrance usnng pointers

    int a = 10;
    inc(a);
    cout << "Inside Main: " << a << "\n";

    return 0;
}