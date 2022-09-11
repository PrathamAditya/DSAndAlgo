#include <iostream>
#include <string>
#include <vector>

using namespace std;

// int nextPrime(int n)
// {
//     int x = 0;
//     for (int i = n; i <= n * n; i++)
//     {
//         if(i%)
//     }
// }

class Pair
{
public:
    int value;
    string key;
};

template <typename T>
class Node
{
public:
    string key;
    T value;
    Node<T> *next;

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
private:
    Node<T> **table;
    int currentSize;
    int tableSize;
    float loadFactor;
    int hashFn(string key)
    {
        int idx = 0;
        int p = 1;

        for (int j = 0; j < key.length(); j++)
        {
            idx = idx + (key[j] * p) % tableSize;
            idx = idx % tableSize;
            p = (p * 27) % tableSize;
        }
        return idx;
    }
    void rehash()
    {
        Node<T> **oldTable = table;
        int oldTableSize = tableSize;
        // or you select next prime!
        tableSize = 2 * tableSize;
        table = new Node<T> *[tableSize];
        for (int i = 0; i < tableSize; i++)
        {
            table[i] = NULL;
        }
        currentSize = 0;
        for (int i = 0; i < tableSize; i++)
        {
            Node<T> *temp = oldTable[i];
            while (temp != NULL)
            {
                insert(temp->key, temp->value);
                temp = temp->next;
            }
            // delete the chain
            if (oldTable[i] != NULL)
            {
                // this is going tbe recurssive destructor call
                delete oldTable[i];
            }
        }
        delete oldTable;
    }

public:
    Hashtable(int ts = 7)
    {
        this->tableSize = ts;
        table = new Node<T> *[tableSize];
        currentSize = 0;
        for (int i = 0; i < tableSize; i++)
        {
            table[i] = NULL;
        }
    }

    void insert(string key, T val)
    {
        int idx = hashFn(key);
        Node<T> *n = new Node<T>(key, val);
        n->next = table[idx];
        table[idx] = n;
        currentSize++;

        // rehash...
        float loadFactor = (currentSize / 1.0 * tableSize);
        if (loadFactor > 0.7)
        {
            rehash();
        }
    }
    void print()
    {
        for (int i = 0; i < tableSize; i++)
        {
            cout << "Bucket: " << i << "->";
            Node<T> *temp = table[i];
            while (temp != NULL)
            {
                cout << temp->value << " ";
                temp = temp->next;
            }
            cout << "\n";
        }
    }
    float getLF()
    {
        return loadFactor;
    }

    T search(string key)
    {
    }
    void erase(string key)
    {
    }
};