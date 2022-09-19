/**
 * author: adityapratham
 **/
#include <iostream>

using namespace std;

int fib(int n)
{
    if (n == 0 || n == 1)
    {
        return n;
    }
    int ans = fib(n - 1) + fib(n - 2);
    return ans;
}

int bottomUp(int n)
{
    int A[n + 1];
    A[0] = 0;
    A[1] = 1;
    if (n == 0)
    {
        return 0;
    }
    else if (n == 1)
    {
        return 1;
    }
    else
    {
        for (int i = 2; i <= n; i++)
        {
            A[i] = A[i - 1] + A[i - 2];
        }
    }
    return A[n];
}

int topDown(int n, int dp[])
{
    if (n == 0 or n == 1)
    {
        return n;
    }
    if (dp[n] != 0)
    {
        return dp[n];
    }
    int ans = topDown(n - 1, dp) + topDown(n - 2, dp);
    return dp[n] = ans;
}

int main()
{
    int dp[100] = {0};
    int n;
    cin >> n;

    cout << topDown(n, dp);
}