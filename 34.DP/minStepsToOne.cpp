/**
 * author: adityapratham
 **/
#include <iostream>

using namespace std;

int funBU(int n)
{
    int A[1000] = {0};
    A[2] = A[3] = 1;

    for (int i = 4; i <= n; i++)
    {
        if (i % 3 == 0)
        {
            A[i] = min(A[i - 1], A[i / 3]) + 1;
        }
        else if (i % 2 == 0)
        {
            A[i] = min(A[i - 1], A[i / 2]) + 1;
        }
        A[i] = A[i - 1] + 1;
    }
    return A[n];
}
int funTD(int n)
{
    if (n == 1)
    {
        return 0;
    }
    else if (n == 2 || n == 3)
    {
        return 1;
    }

    if (n % 3 == 0)
    {
        return min(funTD(n / 3), funTD(n - 1)) + 1;
    }
    else if (n % 2 == 0)
    {
        return min(funTD(n / 2), funTD(n - 1)) + 1;
    }
    return funTD(n - 1) + 1;
}

int main()
{
    // int A[1000] = {0};

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        cout << funBU(n) << "-" << funTD(n);
        cout << "\n";
    }
}