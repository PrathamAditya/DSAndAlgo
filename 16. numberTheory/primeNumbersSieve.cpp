/**
 * author: adityapratham
 **/
#include <bits/stdc++.h>

using namespace std;
// navie approach
bool isPrime(int n)
{
    if (n == 1)
    {
        return false;
    }
    else if (n == 2)
    {
        return true;
    }
    else
    {
        for (int i = 2; i < n; i++)
        {
            /* code */
            if (i % 2 == 0)
            {
                return false;
            }
        }
        return true;
    }
}
// sqrt()
bool isPrime2(int n)
{
    if (n == 1)
    {
        return false;
    }
    else if (n == 2)
    {
        return true;
    }
    else
    {
        for (int i = 2; i * i < n; i++)
        {
            /* code */
            if (i % 2 == 0)
            {
                return false;
            }
        }
        return true;
    }
}

// prime sieve
void primeSieve(int *p)
{
    // first mark all odd prime
    for (int i = 3; i <= 1000000; i++)
    {
        if (i % 2 == 0)
            p[i] = 0;
        else
        {
            p[i] = 1;
        }
    }

    // sieve

    for (int i = 3; i <= 1000000; i = i + 2)
    {
        if (p[i] == 1)
        {
            for (int j = i * i; j <= 1000000; j = j + i)
            {
                p[j] = 0;
            }
        }
    }

    // special
    p[2] = 1;
    p[1] = p[0] = 0;
}

int main()
{
    int n;
    cin >> n;
    int *A = new int[1000005];

    primeSieve(A);
    for (int i = 1; i <= n; i++)
    {
        if (A[i] == 1)
        {
            cout << i << " ";
        }
    }
}
