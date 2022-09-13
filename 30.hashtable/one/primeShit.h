#include <iostream>

using namespace std;

bool isPrime(int n)
{
    int m = n / 2;
    bool flag = 1;

    for (int i = 2; i <= m; i++)
    {
        if (n % i == 0)
        {
            flag = 0;
            break;
        }
    }
    if (flag)
    {
        return 1;
    }

    return 0;
}

int nextPrime(int n)
{
    int num = 0;
    bool flag = 1;
    int k = n;
    int l = k / 2;

    while (flag)
    {
        if (isPrime(k))
        {
            num = k;
            flag = 0;
        }
        k++;
    }
    return num;
}
