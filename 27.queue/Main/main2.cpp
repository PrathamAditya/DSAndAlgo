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

void insertAtTail(Node *&tail, int data)
{
    if (tail == NULL)
    {
        tail = new Node(data);

        return;
    }
    Node *temp = new Node(data);
    tail->next = temp;
    tail = temp;
    return;
}
pair<Node *, Node *> makeQueue()
{
    Node *head = NULL;
    Node *tail = NULL;
    int data;
    cin >> data;
    static bool firstTime = true;
    while (data != -1)
    {
        insertAtTail(tail, data);
        if (firstTime)
        {
            head = tail;
            firstTime = 0;
        }
        cin >> data;
    }
    return make_pair(head, tail);
}

int atfront(Node *head)
{
    return head->data;
}

int atTail(Node *tail)
{
    return tail->data;
}

void print(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}

void pop(Node *&head)
{
    if (head == NULL)
    {
        cout << "Queue is Empty!"
             << "\n";
    }
    Node *temp = head;
    delete head;
    head = temp->next;
}

bool search(Node *head, int key)
{
    if (head == NULL)
    {
        return 0;
    }
    while (head != NULL)
    {
        if (head->data == key)
        {
            return 1;
        }
        head = head->next;
    }
    return 0;
}
int length(Node *head)
{
    int cnt = 0;
    while (head != NULL)
    {
        head = head->next;
        cnt++;
    }
    return cnt;
}

int main()
{
    pair<Node *, Node *> p = makeQueue();
    Node *head = p.first;
    Node *tail = p.second;
    // cout << head->next << " " << tail->data << "\n";
    print(head);
}
