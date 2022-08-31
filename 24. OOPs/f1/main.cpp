#include <iostream>
#include <string>
#include "Hero.cpp"
#include "Hero2.cpp"
using namespace std;

int main()
{
    Hero h1;

    Hero *h2 = new Hero;
}
// {
//     Hero h;
//     h.setHealth(121);
//     h.setLevel('C');
//     char name[8] = "Pratham";
//     h.setName(name);
//     h.print();

//     Hero h2(h);
//     h2.print();

//     h2.name[0] = 'X';
//     h2.print();
//     h2 = h;
//     h2.print();
// }
// {
//     Hero a;
//     a.setHealth(100);
//     a.setLevel('B');

//     cout << "Health: " << a.getHealth() << "\n";
//     cout << "Level: " << a.getLevel() << "\n";

//     Hero *b = new Hero;

//     b->setHealth(1101);
//     b->setLevel('Z');

//     cout << "Health: " << b->getHealth() << "\n";
//     cout << "Level: " << b->getLevel() << "\n";
