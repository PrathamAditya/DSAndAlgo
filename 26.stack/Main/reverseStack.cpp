#include <bits/stdc++.h>
#include <iostream>

using namespace std;
void RStack(stack<int> &s)
{
    stack<int> s2;
    int i = s.size() - 1;
    for (int i = s.size() - 1; i > 0; i--)
    {
        int x = s.top();
        s.pop();
        int y = i;
        while (y--)
        {
            s2.push(s.top());
            s.pop();
        }
        s.push(x);
        int z = i;
        while (z--)
        {
            s.push(s2.top());
            s2.pop();
        }
    }
}

void print(stack<int> s)
{
    while (!s.empty())

    {
        cout << s.top() << " ";
        s.pop();
    }
}

int main()
{
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    print(s);
    cout << "\n";
    RStack(s);
    print(s);
}