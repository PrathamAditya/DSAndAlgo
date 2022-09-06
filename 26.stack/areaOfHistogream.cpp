/**
 * author: adityapratham
 **/
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a[] = {6, 2, 5, 4, 5, 1, 6};
    vector<int> v;
    stack<int> s;
    for (int i = 0; i < a.size(); i++)
    {
        if (s.empty() or s.top() <= a[i])
        {
            s.push(a[i]);
        }
        else
        {
            while (!s.empty() and s.top() > a[i])
            {
                s.pop();
            }
        }

        if (s.empty())
        {
            v.push(a)
        }
    }
    return 0;
}