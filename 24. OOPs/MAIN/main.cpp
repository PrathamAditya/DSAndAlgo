#include <iostream>
#include "Hero2.cpp"

using namespace std;

// data member which is independent to class

int Hero2::timeToComplete = 69;
int main()
{
    // int Hero2::timeToComplete = 69;

    cout << Hero2::random() << "\n";
    // char name[10] = "Pratham";
    // Hero2 h1;

    // h1.SetName(name);
    // h1.SetHealth(100);
    // h1.SetLevel('A');
    // Hero2 *h2 = new Hero2(h1);
    // delete h2;

    // h1.print();
    // cout << "\n";
    // h2.print();
    // cout << "\n";
    // h1.name[0] = 'B';
    // h1.print();
    // cout << "\n";
    // h2.print();

    // static
    // Hero h1;

    // cout << "Health of h1: " << h1.GetHealth() << "\n";

    // dynamic

    // Hero *h1 = new Hero("ABC", 143);
    // h1->SetLevel('S');
    // h1->print();
    // cout << "\n";

    // Hero *h2 = new Hero();
    // h2 = h1;
    // h2->print();
    // h1->name[0] = 'B';
    // cout << "\n";
    // h2->print();
    // cout << "\n";
    // h1->print();
    // Temp t1;
    // cout << sizeof(t1) << "\n";

    // h1.SetName("ABC");
    // cout << h1.GetName();

    // int *a = new int;
    // char *b = new char;
    // int long *c = new long int;

    // cout << sizeof(a) << " " << sizeof(b) << " " << sizeof(c);
}