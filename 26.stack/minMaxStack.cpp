#include <iostream>
#include <vector>

using namespace std;

class Stack
{
private:
    vector<int> v;
    vector<int> minStack;
    vector<int> maxStack;

public:
    void push(int data)
    {
        int curMin = data;
        int curMax = data;
        if (minStack.size())
        {
            curMin = min(minStack[v.size() - 1], data);
            curMax = max(maxStack[v.size() - 1], data);
        }
        v.push_back(data);
        minStack.push_back(curMin);
        maxStack.push_back(curMax);
    }

    void pop()
    {
        if (v.size() == 0)
        {
            cout << "Stack is already empty.";
            return;
        }
        else
        {
            minStack.pop_back();
            maxStack.pop_back();
            v.pop_back();
        }
    }
    int top()
    {
        return v[v.size() - 1];
    }

    int getMax()
    {
        return maxStack[maxStack.size() - 1];
    }
    int getMin()
    {
        return minStack[minStack.size() - 1];
    }
    bool isEmpty()
    {
        return v.size() == 0;
    }
};

int main()
{
    Stack s;

    s.push(19);
    s.push(143);
    s.push(211);
    s.push(10);

    cout << "Empty function: " << s.isEmpty() << "\n";
    cout << "Max: " << s.getMax() << "\n";
    cout << "Min: " << s.getMin() << "\n";
    cout << "top: " << s.top() << "\n";
    // cout << "Before pop: "
    //      << "\n";
    // Stack ss = s;
    // while (!ss.isEmpty())
    // {
    //     cout << ss.top() << " ";
    //     ss.pop();
    // }
    // cout << "\n";

    // s.pop();
    // cout << "After pop: "
    //      << "\n";
    // while (!s.isEmpty())
    // {
    //     cout << s.top() << " ";
    //     s.pop();
    // }
    s.pop();
    cout << "\n";
    cout << "Max: " << s.getMax() << "\n";
    cout << "Min: " << s.getMin() << "\n";
    cout << "top: " << s.top() << "\n";
}