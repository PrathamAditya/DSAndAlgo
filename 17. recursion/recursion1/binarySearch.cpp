/**
 * author: adityapratham
 **/
#include <bits/stdc++.h>

using namespace std;

int BS(vector<int> p, int s, int e, int key)
{
    int mid = (e + s) / 2;
    if (s <= e)
    {
        if (key > p[mid])
        {
            BS(p, mid + 1, e, key);
        }
        else if (key < p[mid])
        {
            BS(p, s, mid - 1, key);
        }
        else
        {
            return mid;
        }
    }
    return -1;
}

int main()
{
    vector<int> p;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        /* code */
        int x;
        cin >> x;
        p.push_back(x);
    }

    if (BS(p, 0, n - 1, 11) == -1)
    {
        cout << "The element is not present.";
    }
    else
        cout << BS(p, 0, n - 1, 11) << "\n";

    return 0;
}