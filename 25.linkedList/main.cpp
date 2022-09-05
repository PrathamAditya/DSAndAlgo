#include <iostream>
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

// class LinkedList
// {
//     Node *head;
//     Node *tail;

// public:
//     LinkedList() {}
//     LinkedList(int d)
//     {
//         Node n(d);
// }
// };

void build() {}
// insert
void insertATHead(Node *&head, int d)
{
    if (head == NULL)
    {
        head = new Node(d);
        return;
    }

    Node *n;
    n = new Node(d);
    n->next = head;
    head = n;
}

int length(Node *head)
{
    int c = 0;

    while (head != NULL)
    {
        c++;
        head = head->next;
    }
    return c;
}
// if you are not maintaing the tail pointer
// void insertAtTail(Node *head, int data)
// {
//     if (head == NULL)
//     {
//         head = new Node(data);
//         return;
//     }
//     Node *tail = head;
//     while (tail->next != NULL)
//     {
//         tail = tail->next;
//     }
//     Node *x = new Node(data);
//     tail->next = x;
//     x = tail;
// }
void insertAtTail(Node *tail, int data)
{
    if (tail == NULL)
    {
        tail = new Node(data);
    }
    Node *x = new Node(data);
    tail->next = x;
    x = tail;
}
void insertAtMiddle(Node *&head, Node *&tail, int d, int p)
{
    if (head == NULL or p == 0)
    {
        insertATHead(head, d);
    }
    else if (p > length(head))
    {
        insertAtTail(tail, d);
    }
    else
    {
        Node *temp = head;
        for (int i = 1; i <= p - 1; i++)
        {
            temp = temp->next;
        }
        Node *n = new Node(d);
        n->next = temp->next;
        temp->next = n;
    }
}

// delete
void deleteHead(Node *&head)
{
    if (head == NULL)
    {
        cout << "NULL"
             << "\n";
        return;
    }
    Node *temp = head->next;
    delete head;
    head = temp;
}

void deleteTail(Node *&head)
{
    if (head == NULL)
    {
        cout << "NULL"
             << "\n";
        return;
    }
    else if (head->next == NULL)
    {
        delete head;
        head = NULL;
        return;
    }
    Node *temp = head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = NULL;
}

void deletePosition(Node *&head, int p)
{
    Node *temp = head;
    if (p == 1)
    {
        deleteHead(head);
    }
    else if (head->next == NULL)
    {
        cout << "Last node deleted!"
             << "\n";
        head = NULL;
        delete head;
    }
    else
    {
        for (int i = 1; i <= p - 1; i++)
        {
            temp = temp->next;
        }
        Node *x = temp->next;
        temp->next = temp->next->next;
        delete x;
    }
}

int search(Node *head, int key)
{
    Node *temp = head;
    int c = 0;
    while (temp != NULL)
    {
        if (temp->data == key)
        {
            return c;
        }
        c++;
        temp = temp->next;
    }
    return -1;
}

bool searchRec(Node *head, int key)
{
    if (head == NULL)
    {
        return false;
    }
    else
    {
        if (head->data == key)
        {
            return true;
        }
        else
        {
            return searchRec(head->next, key);
        }
    }
}

Node *takeInput1()
{
    Node *head = NULL;
    Node *tail = NULL;
    int d;
    cin >> d;
    while (d != -1)
    {
        insertATHead(head, d);

        cin >> d;
    }
    return head;
}

void reverseLL(Node *&head)
{
    if (head == NULL)
    {
        cout << "Null"
             << "\n";
        return;
    }
    else if (head->next == NULL)
    {
        cout << "Done!"
             << "\n";
        return;
    }
    else if (head->next->next == NULL)
    {
        Node *temp = head;
        Node *t2 = head->next->next;
        head->next = temp;
        t2->next = ;
    }
    else
    {
        Node *t1 = NULL;
        Node *t2 = head;
        Node *t3 = head->next;
        Node *t4 = head->next->next;
    }
}

void print(Node *head)
{
    if (head == NULL)
    {
        cout << "List is empty";
    }
    else
    {
        while (head != NULL)
        {
            cout << head->data << " ";
            head = head->next;
        }
    }
    cout << "\n";
}

// Node *takeInput2()
// {
//     Node *head = NULL;
//     Node *tail = NULL;
//     int d;
//     while (cin >> d)
//     {
//         insertATHead(head, d);
//         cout << "s"
//              << "\n";
//     }
//     return head;
// }

int main()
{
    Node *head = takeInput1();

    // Node *tail = NULL;
    // insertATHead(head, 4);
    // tail = head;
    // insertATHead(head, 3);
    // insertATHead(head, 1);
    // insertATHead(head, 0);
    // insertAtMiddle(head, tail, 22, 10);
    // insertATHead(head, 10);
    // insertATHead(head, 100);
    print(head);
    // deletePosition(head, 5);
    // print(head);

    // deleteHead(head);
    // print(head);
    // deleteTail(head);
    // print(head);
}
