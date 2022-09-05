#include <iostream>
#include <stack>
#include <vector>
using namespace std;

void stockSpan(int prices[], int n, int span[])
{
    stack<int> s1;
    stack<int> s2;
    s1.push(prices[0]);
    s2.push(0);
    span[0] = 1;

    for (int i = 1; i < n; i++)
    {
        int curPrice = prices[i];
        while (!s1.empty() and)
    }
}

int main()
{
    int prices[] = {100, 80, 60, 70, 60, 75, 85};
    int n = sizeof(prices) / sizeof(int);
    int span[100000] = {0};

    stockSpan(prices, n, span);
    for (int i = 0; i < n; i++)
    {
        cout << span[i] << " ";
    }
    cout << "\n";
}