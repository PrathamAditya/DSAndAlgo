#include <string.h>
#include <iostream>

using namespace std;
class Hero
{

    // data members
private:
public:
    int health;
    string name;
    char level;
    char *naam;

    // methods
    // setters
    Hero()
    {
        naam = new char[100];
        cout << "This C is called!"
             << "\n";
    }
    Hero(char name[], char naam[])
    {
        naam = new char[100];
        strcpy(this->naam, naam);
        this->name = name;
    }
    Hero(string name, int health, char naam[])
    {
        naam = new char[100];
        strcpy(this->naam, naam);
        this->name = name;
        this->health = health;
    }
    Hero(string name, int health, char level, char naam[])
    {
        naam = new char[100];
        strcpy(this->naam, naam);
        this->name = name;
        this->health = health;
        this->level = level;
    }

    // copy construtor!
    Hero(Hero &t)
    {
        this->name = t.name;
        this->health = t.health;
        this->name = t.name;

        cout << "Copy C is Called!"
             << "\n";
    }

    // getter and setters

    // getters

    void print()
    {
        cout << "[" << name << "," << level << "," << health << "]";
    }
};