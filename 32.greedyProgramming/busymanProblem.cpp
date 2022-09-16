/**
 * author: adityapratham
 **/
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<pair<int, int>> v;
        int min = INT_MAX;
        int max = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            int a, b;
            cin >> a >> b;
            if (min > a)
            {
                min = a;
            }
            if (max < b)
            {
                max = b;
            }
            v.push_back(make_pair(b, a));
        }
        sort(v.begin(), v.end());
        int ans = 0;
        for (int i = 0; i < n - 1; i++)
        {
            if (v[i].first <= v[n - 1].first)
            {
                if (i == 0)
                {

                    ans++;
                }
                else
                {
                    if (v[i].second >= v[i - 1].first)
                    {

                        ans++;
                    }
                }
            }
            else
            {
                break;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}