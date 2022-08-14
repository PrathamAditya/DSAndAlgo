#include <iostream>
#include <string>

using namespace std;

// acess specifiers
// definig a new datatype
class Car
{
public:
    float price;
    int model_no;
    string name;

    void print()
    {
        cout << "Name " << name << endl;
        cout << "Model No." << model_no << endl;
        cout << "Price " << price << "\n";
    }
    void apply_discount(float x)
    {
        price = price * (1.0 - x);
    }
    float get_discounted_price(float x)
    {
        apply_discount(x);
        return price - (1 - x);
    }
};
class Hero
{
public:
    string name;
    int health;
    char level;
};

int main(int argc, const char **argv)
{

    Hero h1;
    h1.name = "Pratham";

    cout << h1.name << " "
         << "\n";

    return 0;
}