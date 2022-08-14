/**
 * author: adityapratham
 **/
#include <bits/stdc++.h>

using namespace std;

string extractString(string str, int key)
{
    // now you have to acess the underlying array
    char *s = strtok((char *)str.c_str(), " ");
    while (key > 1)
    {
        s = strtok(NULL, " ");
        key--;
    }
    return (string)s;
}

int main()
{

    int n;
    cin >> n;

    // consuming the white space
    cin.get();

    string a[100];
    for (int i = 0; i < n; i++)
    {
        getline(cin, a[i]);
    }

    int key;

    string reversal, ordering;

    return 0;
}
