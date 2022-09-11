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

public:
    Hashtable(int ts = 7)
    {
        this->tableSize = ts;
        table = new Node<T> *[tableSize];
        currentSize = 0;
        loadFactor = 0;
        for (int i = 0; i < tableSize; i++)
        {
            table[i] = NULL;
        }
    }

    void rehash()
    {
        vector<Pair> A;
        for (int i = 0; i < tableSize; i++)
        {
            Node<T> *temp = table[i];
            while (temp != NULL)
            {
                Pair x;
                x.value = temp->value;
                x.key = temp->key;
                A.push_back(x);
                temp = temp->next;
            }
        }
        Node<T> **temp = table;
        tableSize = tableSize * 2 + 3;
        table = new Node<T> *[tableSize];
        currentSize = 0;

        for (int i = 0; i < A.size(); i++)
        {
            Pair x = A[0];
            insert(x.key, x.value);
        }
    }

    void insert(string key, T val)
    {
        int idx = hashFn(key);
        Node<T> *n = new Node<T>(key, val);
        n->next = table[idx];
        table[idx] = n;
        currentSize++;
        loadFactor = (currentSize / tableSize);

        // rehash...
        if (loadFactor >= 0.75)
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