#include <iostream>
#include <stack>
using namespace std;

class Stack
{
private:
    int cnt = 0;
    stack<int> s1;
    stack<int> s2;

public:
    bool isEmpty()
    {
        return cnt == 0;
    }
    void push(int data)
    {
        s1.push(data);
        cnt++;
    }
    void pop()
    {
        if (!s1.empty())
        {
            int a = cnt;
            for (int i = 0; i < a - 1; i++)
            {
                int x = s1.top();
                s1.pop();
                s2.push(x);
            }
            s1.pop();
            for (int i = 0; i < a - 1; i++)
            {
                int x = s2.top();
                s2.pop();
                s1.push(x);
            }
            cnt--;
        }
    }
    int getFront()
    {
        int x;
        if (!s1.empty())
        {
            int a = cnt;
            for (int i = 0; i < a; i++)
            {
                int x = s1.top();
                s1.pop();
                s2.push(x);
            }
            x = s2.top();

            for (int i = 0; i < a; i++)
            {
                int x = s2.top();
                s2.pop();
                s1.push(x);
            }
        }
        return x;
    }
    int getLenght()
    {
        return cnt;
    }
    int getTop()
    {
        return s1.top();
    }
};

int main()
{
    Stack s;
    for (int i = 1; i <= 5; i++)
    {
        s.push(i * i * i);
    }
    s.pop();
    s.pop();
    while (!s.isEmpty())
    {
        cout << s.getFront() << " ";
        s.pop();
    }
}