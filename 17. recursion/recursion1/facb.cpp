/**
 * author: adityapratham
 **/
#include <bits/stdc++.h>

using namespace std;
int facb(int n)
{
    // base case
    if (n == 0)
    {
        return 0;
    }
    else if (n == 1)
    {
        return 1;
    }
    // recursive case
    return facb(n - 1) + facb(n - 2);
}

int main()
{
    int n;
    cin >> n;

    cout << "Fibonacci of " << n << ": " << facb(n) << "\n";
}