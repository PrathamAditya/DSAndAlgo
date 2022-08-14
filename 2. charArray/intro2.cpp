/**
 * author: adityapratham
 **/
#include <bits/stdc++.h>

using namespace std;
void readline(char a[], int maxLen, char delim = '\n')
{
    int i = 0;
    char ch = cin.get();
    while (ch != delim)
    {
        a[i] = ch;
        i++;
        if (i == (maxLen - 1))
        {
            break;
        }
        ch = cin.get();
    }
    a[i] = '\0';
    return;
}

int main()
{
    char a[1000];

    cin.getline(a, 1000, '#');
    cout << a << "\n";

    return 0;
}