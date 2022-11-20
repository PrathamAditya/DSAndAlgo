/**
 * author: adityapratham
 **/
#include <iostream>
#include <string>

using namespace std;

class Human
{
private:
    int age;
    int height;
    int weight;
    string name;

public:
    // setters
    int GetAge()
    {
        return this->age;
    }
    void SetWeight(int weight)
    {
        this->weight = weight;
    }
};

class Man : public Human
{
private:
    int a;
    int GetAge()
    {
        return this->a;
    }

public:
    string color;

    string GetColor()
    {
        return this->color;
    }
};
int main()
{

    Man obj1;
    cout << obj1.Human::GetAge();
    // Man obj1;
    // cout << obj1.GetAge() << "\n";
}