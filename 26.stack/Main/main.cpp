#include <iostream>
#include <vector>

using namespace std;

class Stack
{
private:
    vector<int> v;
    int top = -1;
    int maxSize;
    int min = INT_MAX;
    int max = INT_MIN;

public:
    Stack(int size = 5)
    {
        this->maxSize = size;
    }
    void push(int data)
    {
        if (top <= maxSize - 1)
        {
            if (data > max)
            {
                max = data;
            }
            if (data < min)
            {
                min = data;
            }
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
    int getMin()
    {
        if (top == -1)
        {
            cout << "Stack is empty!"
                 << "\n";
        }
        int min = INT_MAX;
        for (auto x : v)
        {
            if (min > x)
            {
                min = x;
            }
        }
        return min;
    }
    int getMax()
    {
        if (top == -1)
        {
            cout << "Stack is empty!"
                 << "\n";
        }
        int max = INT_MIN;
        for (auto x : v)
        {
            if (max < x)
            {
                max = x;
            }
        }
        return max;
    }
};

int main()
{
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.print();
    cout << endl;
    cout << s.getMax();
    cout << "\n";
    s.pop();
    cout << s.getMax();
    // cout << "\n";
    // s.pop();
    // s.print();
    // cout << "\n";
    // cout << s.topElement();
    // cout << "\n";
    // cout << s.isEmpty();
    // cout << "\n";
    // cout << s.isFull();
    // s.push(10);
    // cout << "\n";
    // cout << s.isFull();
}