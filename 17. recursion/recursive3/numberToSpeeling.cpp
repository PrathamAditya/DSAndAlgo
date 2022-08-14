/**
 * author: adityapratham
 **/
#include <bits/stdc++.h>

using namespace std;

void fun(vector<int> a, int n)
{
    if (n == 0)
    {
        return;
    }
    vector<string> s = {"zero",
                        "one",
                        "two",
                        "three",
                        "four",
                        "five",
                        "six",
                        "seven",
                        "eight",
                        "nine"};
    int x = a[0];
    cout << s[x] << " ";
    vector<int> b;
    b = std::vector<int>(a.begin() + 1, a.end());
    fun(b, n - 1);
}

char words[][10] = {"zero", "one",
                    "two",
                    "three",
                    "four",
                    "five",
                    "six",
                    "seven",
                    "eight",
                    "nine"};

void fun2(int n)
{
    if (n == 0)
    {
        return;
    }
    else
    {
        fun2(n / 10);
        int d = n % 10;
        cout << words[d] << " ";
        return;
    }
}

int main()
{
    int n;
    cin >> n;

    // vector<int> A;
    // for (int i = 0; i < n; i++)
    // {
    //     int ii;
    //     cin >> ii;
    //     A.push_back(ii);
    // }

    // fun(A, n);

    fun2(n);
    return 0;
}