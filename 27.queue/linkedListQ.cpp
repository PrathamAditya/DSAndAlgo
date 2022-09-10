#include <iostream>
#include <list>

using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node() {}

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

// class Queue
// {
// private:
//     Node *head = NULL;
//     Node *tail = NULL;

// public:
//     bool empty()
//     {
//         return head == NULL;
//     }

//     void push(int data)
//     {
//         Node *temp = new Node(data);

//         if (head == NULL)
//         {
//             head = temp;
//             tail = temp;
//         }
//         else
//         {
//             head->next = temp;
//             tail = temp;
//         }
//     }

//     void pop()
//     {
//         if (head == tail and head != NULL)
//         {
//             delete head;
//             head = NULL;
//         }
//         else if (head == tail and head == NULL)
//         {
//             cout << "Queue is empty."
//                  << "\n";
//         }
//         else
//         {
//             Node *t = head;
//             head = head->next;
//             delete t;
//         }
//     }
//     int getFront()
//     {
//         return head->data;
//     }
// };
class Queue
{
private:
    int cs;
    list<int> l;

public:
    Queue()
    {
        cs = 0;
    }

    bool isEmpty()
    {
        return cs == 0;
    }

    void push(int data)
    {
        l.push_back(data);
        cs++;
    }

    void pop()
    {
        if (!isEmpty())
        {
            l.pop_front();
            cs--;
        }
        else
        {
            cout << "Queue is empty."
                 << "\n";
        }
    }
    int getFront()
    {
        return l.front();
    }
};

int main()
{
    Queue q;
    for (int i = 1; i <= 10; i++)
    {
        q.push(i);
    }
    while (!q.isEmpty())
    {
        cout << q.getFront() << " ";
        q.pop();
    }
}