#include <iostream>

using namespace std;

int long long fun(int n, int p)
{
    if (n == 1 || n == 0)
    {
        return n;
    }
    if (p == 0)
    {
        return 1;
    }
    return n * fun(n, p - 1);
}

int main()
{
    int tt;
    cin >> tt;

    while (tt--)
    {
        int n, p;
        cin >> n >> p;
        cout << "Answer: " << fun(n, p) << "\n";
    }
}