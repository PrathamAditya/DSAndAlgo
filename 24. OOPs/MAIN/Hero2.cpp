#include <string.h>
#include <iostream>

using namespace std;
class Hero2
{

    // data members
private:
    char level;

public:
    int health;
    char *name;
    static int timeToComplete;

    // methods
    // setters      << "\n";
    // copy construtor!

    Hero2()
    {
        name = new char[100];
        // strcpy(this->name, name);
    }
    Hero2(int health)
    {
        // this->name = new char[100];
        // strcpy(this->name, name);
        this->name = name;
        this->health = health;
    }
    Hero2(int health, char level)
    {
        // name = new char[100];
        // strcpy(this->name, name);
        this->health = health;
        this->level = level;
    }
    Hero2(Hero2 &t)
    {
        char *ch = new char[strlen(t.name) + 1];
        strcpy(ch, t.name);
        this->name = ch;
        this->level = t.level;
        this->health = t.health;

        cout << "Copy C is Called!"
             << "\n";
    }

    // getter and setters
    void SetName(char name[])
    {
        strcpy(this->name, name);
    }
    void SetHealth(int health)
    {
        this->health = health;
    }

    void SetLevel(char level)
    {
        this->level = level;
    }

    // getters

    void print()
    {
        cout << "[" << name << "," << level << "," << health << "]";
    }

    static int random()
    {
        return timeToComplete;
    }
    ~Hero2()
    {
        cout << "Dis is called"
             << "\n";
    }
};