/**
 * author: adityapratham
 **/
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cout << "Enter n: ";
    cin >> n;

    int len = 0;
    string s;

    while (n--)
    {
        char a[1000];
        cout << "Enter: ";
        cin >> a;
        if (len < strlen(a))
        {
            len = strlen(a);
            s = a;
        }
    }
    cout << len << "\n";
    cout << s << "\n";

    return 0;
}