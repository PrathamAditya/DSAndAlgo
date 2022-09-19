/**
 * author: adityapratham
 **/
#include <iostream>
#include <vector>

using namespace std;

int topDown(int n, vector<int> A)
{
    if (n == 1)
    {
        return 1;
    }
    int x = 0;
    for (int i = 0; i < A.size() - 1; i++)
    {
        x = min(topDown(n - A[i], A), topDown(n - A[i + 1], A));
    }
    return x + 1;
}

int main()
{
    vector<int> A = {1, 7, 10};
    int n;
    cin >> n;

    cout << topDown(n, A);

    return 0;
}