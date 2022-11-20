#include <iostream>
#include <vector>

using namespace std;

template <typename T>
class Stack
{
private:
    vector<T> v;
    int top = -1;
    int maxSize;

public:
    Stack(int size = 5)
    {
        this->maxSize = size;
    }
    void push(T data)
    {
        if (top <= maxSize - 1)
        {
            v.push_back(data);
            top++;
        }
        else
        {
            cout << "Size is full"
                 << "\n";
            return;
        }
    }
    void pop()
    {
        if (top == -1)
        {
            cout << "Stacl is Empty."
                 << "\n";
            return;
        }
        v.pop_back();
        top--;
    }
    int topElement()
    {
        return v[top];
    }

    void print()
    {
        int i = top;
        while (i >= 0)
        {
            cout << v[i] << " ";
            i--;
        }
    }

    // is emepty

    bool isEmpty()
    {
        return top == -1;
    }
    bool isFull()
    {
        return top == maxSize - 1;
    }
};

int main()
{
    Stack<float> s;
    s.push(1.11);
    s.push(2.232);
    s.push(3.233);
    s.push(42.32);
    s.push(52323.23);
    s.print();
    cout << "\n";
    s.pop();
    s.print();
    cout << "\n";
    cout << s.topElement();
    cout << "\n";
    cout << s.isEmpty();
    cout << "\n";
    cout << s.isFull();
    s.push(10);
    cout << "\n";
    cout << s.isFull();
}