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

class Man : protected Human
{
public:
    string color;

    string GetColor()
    {
        return this->color;
    }
};

class Male : public Man
{

public:
    void fun()
    {
        cout << GetAge();
    }
    // void sleep()
    // {
    //     cout << "he is sleeping!"
    //          << "\n";
    // }
};
int main()
{

    Male obj1;
    cout << obj1.color << "\n";
    // Man obj1;
    // cout << obj1.GetAge() << "\n";
}