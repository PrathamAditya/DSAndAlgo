#include <iostream>
#include <list>

using namespace std;
class Deque
{
private:
    list<int> l;

public:
    bool empty()
    {
        return l.empty();
    }
    void pop_front()
    {
        if (empty())
        {
            l.pop_front();
        }
    }
    void pop_back()
    {
        if (empty())
        {
            l.pop_back();
        }
    }
    void push_front(int data)
    {
        l.push_front(data);
    }
    void push_back(int data)
    {
        l.push_front(data);
    }

    int front()
    {
        return *l.begin();
    }
    int back()
    {
        return *l.end();
    }
};

int main()
{
    Deque d;
    d.push_back(10);
    d.push_back(12);
    d.push_back(14);
    d.push_back(15);

    while (!d.empty())
    {
        cout << d.front() << " ";
        d.pop_front();
    }
}