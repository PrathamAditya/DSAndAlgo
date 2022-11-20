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

void insertAtHead(Node *&head, int data)
{
    if (head == NULL)
    {
        head = new Node(data);
        return;
    }
    Node *temp = new Node(data);
    temp->next = head;
    head = temp;
    return;
}

pair<Node *, Node *> makeLL()
{
    Node *head = NULL;
    Node *tail = NULL;
    int data;
    cin >> data;
    static bool firstTime = true;
    while (data != -1)
    {
        insertAtHead(head, data);
        if (firstTime)
        {
            tail = head;
            firstTime = 0;
        }
        cin >> data;
    }
    return make_pair(head, tail);
}

void print(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
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

////////Queue

int main()
{
    pair<Node *, Node *> p = makeLL();
    Node *head = p.first;
    Node *tail = p.second;
}