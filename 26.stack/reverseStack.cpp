#include <iostream>
#include <stack>
#include <vector>

using namespace std;

void transfer(stack<int> &s1, stack<int> &s2, int n)
{
    for (int i = 0; i < n; i++)
    {
        s2.push(s1.top());
        s1.pop();
    }
}

void reverseStack(stack<int> &s1)
{
    // helper stack
    stack<int> s2;
    int n = s1.size();
    for (int i = 0; i < n; i++)
    {
        int x = s1.top();
        s1.pop();
        transfer(s1, s2, n - i - 1);
        s1.push(x);
        transfer(s2, s1, n - i - 1);
    }
}
void insertAtBottom(stack<int> &s, int x)
{
    if (s.empty())
    {
        s.push(x);
        return;
    }
    int data = s.top();
    s.pop();
    insertAtBottom(s, x);
    s.push(data);
}

void reverseUsingRecursion(stack<int> &s)
{
    if (s.size() == 0)
    {
        return;
    }
    int x = s.top();
    s.pop();
    reverseUsingRecursion(s);
    insertAtBottom(s, x);
}

int main()
{
    stack<int> s;
    s.push(10);
    s.push(11);
    s.push(122);
    s.push(1);
    s.push(98);

    while (!s.empty())
    {
        cout << s.top() << "\n";
        s.pop();
    }
    // reverseUsingRecursion(s);
    // while (!s.empty())
    // {
    //     cout << s.top() << "\n";
    //     s.pop();
    // }
}