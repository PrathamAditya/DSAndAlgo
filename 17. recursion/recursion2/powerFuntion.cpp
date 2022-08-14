/**
 * author: adityapratham
 **/
#include <bits/stdc++.h>

using namespace std;
int power(int a, int n)
{
    if (n == 0)
    {
        return 1;
    }
    else
    {
        return a * power(a, n - 1);
    }
}
int fastPower(int a, int n)
{
    if (n == 0)
    {
        return 1;
    }
    else
    {
        int x = fastPower(a, n / 2);
        if (n % 2 == 0)
        {
            return x * x;
        }
        else
        {
            return x * x * a;
        }
    }
}
int main()
{
    int a, b;
    cin >> a >> b;

    cout << "Ans: " << power(a, b) << '\n';
    cout << "Ans: " << fastPower(a, b) << "\n";
    return 0;
}