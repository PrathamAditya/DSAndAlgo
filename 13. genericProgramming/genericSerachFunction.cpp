/**
 * author: adityapratham
 **/
#include <list>
#include <iostream>

using namespace std;

// ForwardIt

// what type of contaier and what type of datatype

template <class ForwardIterator, class T>

ForwardIterator searchL(ForwardIterator start, ForwardIterator end, T key)
{
    while (start != end)
    {
        if (*start == key)
        {
            return start;
        }
        start++;
    }
    return end;
}

int main()
{
    /*

     */

    int arr[] = {1, 3, 5, 7, 10, 12};
    int n = sizeof(arr) / sizeof(int);

    list<int> l;
    l.push_back(1);
    l.push_back(2);
    l.push_back(3);
    l.push_back(4);

    auto it = searchL(l.begin(), l.end(), 3);
    if (*it == n)
    {
        cout << "The element is not present."
             << "\n";
    }
    else
    {
        cout << *it << "\n";
    }

    return 0;
}