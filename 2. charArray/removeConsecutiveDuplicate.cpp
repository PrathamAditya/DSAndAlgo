/**
 * author: adityapratham
 **/
#include <bits/stdc++.h>

using namespace std;
void removeCD(char a[])
{
    int l = strlen(a);
    char x;

    for (int i = 0; i < l; i++)
    {
        if (i == 0)
        {
            cout << a[i];
            x = a[i];
        }
        else
        {
            if (a[i] != x)
            {
                cout << a[i];
                x = a[i];
            }
        }
    }
}

int main()
{
    char a[1000];
    cin.getline(a, 1000);
    removeCD(a);

    return 0;
}