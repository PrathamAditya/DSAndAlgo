
#include <iostream>

using namespace std;

#define ll long long
#define ull unsigned long long ll

void fun(ll n)
{
    ll A[1000000];
    for (int i = 0; i <= 1000000; i++)
    {
        /* code */
        if (i % 2 == 0)
        {
            A[i] = 0;
        }
        else
        {
            A[i] = 1;
        }
    }

    //
    for (ll i = 3; i <= 1000000; i = i + 2)
    {
        if (A[i] == 1)
        {
            for (ll j = A[i] * A[i]; j <= 1000000; j = j + A[i])
            {
                A[j] = 0;
            }
        }
    }

    A[2] = 1;
    A[0] = A[1] = 0;
    for (ll i = 0; i < n; i++)
    {
        /* code */
        if (A[i] != 0)
        {
            cout << i << " ";
        }
    }
}
int main()
{
    ll n;
    cin >> n;
    fun(n);

    return 0;
}