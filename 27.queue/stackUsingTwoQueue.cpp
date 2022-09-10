#include <iostream>
#include <queue>
using namespace std;

class Stack
{
private:
    queue<int> q1;
    queue<int> q2;
    int cnt = 0;

public:
    void
    push(int data)
    {
        q1.push(data);
        cnt++;
    }
    int getTop()
    {
        return q1.back();
    }
    bool isEmpty()
    {
        return cnt == 0;
    }
    void pop()
    {
        int a = cnt;
        for (int i = 1; i < a; i++)
        {
            int x = q1.front();
            q1.pop();
            q2.push(x);
        }
        q1.pop();
        for (int i = 1; i < a; i++)
        {
            int x = q2.front();
            q2.pop();
            q1.push(x);
        }
        cnt--;
    }
    int getLength()
    {
        return cnt;
    }
};

int main()
{
    Stack s;
    for (int i = 1; i <= 5; i++)
    {
        s.push(i);
    }

    while (!s.isEmpty())
    {
        cout << s.getTop() << " ";
        s.pop();
    }
}