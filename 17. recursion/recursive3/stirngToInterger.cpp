/**
 * author: adityapratham
 **/
#include <bits/stdc++.h>

using namespace std;

int stringToInt(char a[], int n)
{
    if (n == 0)
    {
        return 0;
    }
    stringToInt(a, n - 1);
    cout << a[n - 1] - '0';
}

int main()
{

    char a[] = "1234";
    int n = strlen(a);

    cout << stringToInt(a, n);

    return 0;
}