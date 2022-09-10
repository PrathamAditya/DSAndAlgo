#include <iostream>

using namespace std;

class Queue
{
private:
    int A[100];
    int n;
    int rear = -1;
    int front = -1;

public:
    Queue() { this->n = 10; }
    Queue(int n)
    {
        this->n = n;
    }
    void pop()
    {
        if (front == -1)
        {
            cout << "Queue is empty."
                 << "\n";
            return;
        }
        else
        {
            A[front] = -1;
            front++;
        }
    }
    void push(int data)
    {
        if (rear == n - 1)
        {
            cout << "Queue is full."
                 << "\n";
            return;
        }
        else
        {
            if (front == -1)
            {
                front++;
            }
            rear++;
            A[rear] = data;
        }
    }
    int getFront()
    {
        if (front == -1)
        {
            cout << "Queue is empty."
                 << "\n";
            return -1;
        }
        return A[front];
    }
    void print()
    {
        for (int i = front; i <= rear; i++)
        {
            cout << A[i] << " ";
        }
        cout << "\n";
    }
};
class Queue2
{
private:
    int *arr;
    int f, r, cs, ms;

public:
    Queue2(int ds = 5)
    {
        arr = new int[ds];
        cs = 0;
        ms = ds;
        f = 0;
        r = ms - 1;
    }
    bool full()
    {
        return cs == ms;
    }
    bool empty()
    {
        return cs == 0;
    }
    void push(int data)
    {
        if (!full())
        {
            r = (r + 1) % ms;
            arr[r] = data;
            cs++;
        }
    }
    void pop()
    {
        if (!empty())
        {
            f = (f + 1) % ms;
            cs--;
        }
    }

    int front()
    {
        return arr[f];
    }

    void print()
    {
        if (f > r)
        {
            for (int i = f; i < ms; i++)
            {
                cout << arr[i] << " ";
            }
            for (int i = 0; i <= r; i++)
            {
                cout << arr[i] << " ";
            }
            cout << "\n";
        }
        else
        {
            for (int i = f; i <= r; i++)
            {
                cout << arr[i] << " ";
            }
            cout << "\n";
        }
    }

    ~Queue2()
    {
        if (arr != NULL)
        {
            delete[] arr;
            arr = NULL;
        }
    }
};

int main()
{
    // Queue q(5);
    // q.push(11);
    // q.push(1);
    // q.push(2);
    // q.push(3);
    // q.push(4);
    // q.print();
    // q.pop();
    // q.print();
    // q.push(1);
    // q.print();
    Queue2 q;
    for (int i = 1; i <= 6; i++)
    {
        q.push(i);
    }

    q.pop();
    q.pop();

    q.push(7);

    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    return 0;
}