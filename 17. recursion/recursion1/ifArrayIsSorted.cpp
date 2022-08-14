/**
 * author: adityapratham
 **/
#include <bits/stdc++.h>

using namespace std;

bool fun(vector<int> a, int n)
{
    if (n == 1 || n == 0)
        return 1;
    else
    {
        vector<int> b;
        b = std::vector<int>(a.begin() + 1, a.end());
        fun(b, n - 1);
        if (a[0] > b[0])
        {
            return false;
        }
    }
    return true;
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
    bool isT = fun(p, 5);
    if (isT)
    {
        cout << "Sorted"
             << "\n";
    }
    else
    {
        cout << "Not Sorted"
             << "\n";
    }
}