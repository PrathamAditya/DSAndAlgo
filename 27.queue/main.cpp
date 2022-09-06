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

int main()
{
    Queue q(5);
    q.push(11);
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.print();
    q.pop();
    q.print();
    q.push(1);
    q.print();
}