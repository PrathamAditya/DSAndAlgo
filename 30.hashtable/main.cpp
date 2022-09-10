#include <iostream>
#include <string>

using namespace std;
template <typenameT>
class Node
{
private:
    string key;
    T value;
    Node<T> *next;

public:
    Node(string key, T value)
    {
        this->value = value;
        this->key = key;
        next = NULL;
    }
    ~Node()
    {
        if (next != NULL)
        {
            delete next;
        }
    }
};

template <typename T>
class Hashtable
{
    Node<T> **table;
    int currentSize;
    int tableSize;

public:
    Hashtable(int ts = 7)
    {
        this->tableSize = ts;
        table = new Node<T> *[tableSize];
        currentSize = 0;
        for (int i = 0; i < table; i++)
        {
            table[i] = NULL;
        }
    }

    void insert(string k, T value)
    {
    }

    T search(string key)
    {
    }
    void erase(string key)
    {
    }
};

int main()
{
}