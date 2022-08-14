#include <iostream>
#include <string>

using namespace std;
class Hero
{
private:
    int health;
    char level;

public:
    // getters
    char *name;
    int getHealth()
    {
        return health;
    }
    char getLevel()
    {
        return level;
    }

    void print()
    {
        cout << "Name: " << this->name << "\n";
        cout << "Health: " << this->health << "\n";
        cout << "Level: " << this->level << "\n";
    }

    // default
    Hero()
    {
        cout << "The constructor is called"
             << "\n";
        name = new char[100];
    }
    // parameter
    Hero(int health)
    {
        this->health = health;
    }
    Hero(int health, char level)
    {
        this->health = health;
        this->level = level;
    }
    // copy constructor

    Hero(Hero &temp)
    {
        char *ch = new char[strlen(temp.name) + 1];
        strcpy(ch, temp.name);
        this->name = ch;
        this->health = temp.health;
        this->level = temp.level;
    }

    // setters
    void setHealth(int x)
    {
        health = x;
    }
    void setLevel(char x)
    {
        level = x;
    }
    void setName(char name[])
    {
        strcpy(this->name, name);
    }
    void setName(string x, string y)
    {
        if (y == "Vasu")
        {
            cout << "You are good to go!"
                 << "\n";
        }
        else
        {
            cout << "You dont have acess to this."
                 << "\n";
        }
    }
    ~Hero()
    {
        cout << "Destructor called"
             << "\n";
    }
};