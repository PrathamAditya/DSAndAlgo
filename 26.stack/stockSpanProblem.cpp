#include <iostream>
#include <stack>
#include <vector>
using namespace std;

void stockSpan(int prices[], int n, int span[])
{
    stack<int> s1;
    s1.push(0);
    span[0] = 1;

    for (int i = 1; i < n; i++)
    {
        int curPrice = prices[i];
        int topp = s1.top();
        while (!s1.empty() and prices[s1.top()] <= curPrice)
        {
            s1.pop();
        }
        if (!s1.empty())
        {
            int preHighest = s1.top();
            span[i] = i - preHighest;
        }
        else
        {
            span[i] = i + 1;
        }
        s1.push(i);
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