/**
 * author: adityapratham
 **/
#include <list>
#include <iostream>
#include <string>

using namespace std;

class Book
{
public:
    string name;
    int price;

    Book()
    {
    }
    Book(string name, int price)
    {
        this->name = name;
        this->price = price;
    }
};
class BookCompare
{
public:
    // overloaded
    bool opertor()(Book A, Book B)
    {
        if (A.name == B.name)
        {
            return true;
        }
    }
};

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
    Book b1("C++", 100); // old edition
    Book b2("Python", 120);
    Book b3("Java", 130);
    Book b4(b1);

    list<Book> l;
    l.push_back(b1);
    l.push_back(b2);
    l.push_back(b3);

    Book bookToFind("C++", 110); // new editon

    return 0;
}