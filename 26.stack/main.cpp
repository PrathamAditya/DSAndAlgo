#include <iostream>
#include <vector>
using namespace std;

// template class
template <typename T>

class Stackk
{
private:
    vector<T> x;

public:
    void insert(T data)
    {
        x.push_back(data);
    }
    void pop()
    {
        if (!isEmpty())
        {
            x.pop_back();
        }
    }
    T topp()
    {
        return x[x.size() - 1];
    }

    bool isEmpty()
    {
        return x.size() == 0;
    }
    void print()
    {
        for (int i = x.size() - 1; i >= 0; i--)
        {
            cout << x[i] << " ";
        }
        cout << "\n";
    }
};

class Stack
{
public:
    vector<int> x;
    int top = -1;
    int size;
    Stack()
    {
    }
    Stack(int size)
    {
        this->size = size;
    }

    void insert(int data)
    {
        if (top + 1 == this->size)
        {
            cout << "Can't push more elements"
                 << "\n";
            return;
        }
        else
        {
            x.push_back(data);
            top++;
        }
    }
    int pop()
    {
        if (!isEmpty())
        {
            int a = x[top];
            x.pop_back();
            top--;
            return a;
        }
        return -1;
    }
    int topp()
    {
        if (top == -1)
        {
            return -1;
        }

        int a = x[top];
        return a;
    }

    bool isEmpty()
    {
        if (top == -1)
        {
            return 1;
        }
        return 0;
    }
    void print()
    {
        for (int i = top; i >= 0; i--)
        {
            cout << x[i] << " ";
        }
        cout << "\n";
    }
};
int main()
{
    // Stack s1;
    // cout << s1.isEmpty();
    // cout << "\n";
    // s1.insert(1);
    // s1.insert(10);
    // s1.insert(11);
    // s1.insert(111);
    // s1.print();
    // s1.pop();
    // s1.pop();
    // s1.print();
    // Stack s2(5);
    // for (int i = 0; i < 5; i++)
    // {
    //     s2.insert(i * i);
    // }

    // while (!s2.isEmpty())
    // {
    //     cout << s2.topp() << "\n";
    //     s2.pop();
    // }
    Stackk<int> s;
    for (int i = 1; i <= 5; i++)
    {
        s.insert(i * i);
    }

    while (!s.isEmpty())
    {
        cout << s.topp() << " ";
        s.pop();
    }
}