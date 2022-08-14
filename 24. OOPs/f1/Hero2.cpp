#include <iostream>

using namespace std;

class Hero2
{
private:
    int health;
    int health2;
    char level;
    char level2;
    char level3;
    char level4;

public:
    int getHealth()
    {
        return health;
    }
    // char getLevel()
    // {
    //     return level;
    // }

    void setHealth(int h)
    {
        health = h;
    }

    // void setLevel(char l)
    // {
    //     level = l;
    // }
};