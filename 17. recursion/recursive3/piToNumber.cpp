#include <iostream>
#include <vector>

using namespace std;

void fun(vector<char> a, int i, int n)
{
    if (i >= n - 1)
    {
        return;
    }
    if (a[i] == 'p' and a[i + 1] == 'i')
    {
        vector<char> aa = std::vector<char>(a.begin(), a.begin() + i);
        vector<char> bb = std::vector<char>(a.begin() + i + 1, a.end());
        vector<char> cc{'3', '.', '1', '4'};

        a = aa + cc + bb;
    }
}
int main()
{
    vector<char> a;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        char aa;
        cin >> aa;
        a.push_back(aa);
    }
}