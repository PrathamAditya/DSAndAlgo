
#include <bits/stdc++.h>

using namespace std;
bool isP(char a[])
{
    int n = strlen(a);
    int i = 0;
    int j = n - 1;

    while (i <= j)
    {
        if (a[i] != a[j])
        {
            return 0;
        }
        else
        {
            i++;
            j--;
        }
    }
    return 1;
}

int main()
{
    char ch[1000];
    cin.getline(ch, 1000);

    if (isP(ch))
    {
        cout << "YES"
             << "\n";
    }
    else
    {
        cout << "NO"
             << "\n";
    }

    return 0;
}