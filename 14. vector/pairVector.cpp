#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// bool compare(pair<int, int> p1, pair<int, int> p2)
// {
//     int d1 = p1.first * p1.first + p1.second * p1.second;
//     int d2 = p2.first * p2.first + p2.second * p2.second;
//     if (d1 == d2)
//     {
//         return p1.first < p1.second;
//     }
//     return d1 < d2;
// }

class Car
{
public:
    string name;
    int x;
    int y;

    Car()
    {
    }
    Car(string n, int x, int y)
    {
        name = n;
        this->x = x;
        this->y = y;
    }
    int dist()
    {
        return x * x + y * y;
    }
};
bool compare(Car c1, Car c2)
{
    int d1 = c1.dist();
    int d2 = c2.dist();
    if (d1 == d2)
    {
        return c1.name.length() < c2.name.length();
    }
    return d1 < d2;
}

int main(int argc, char const *argv[])
{
    /* code */
    vector<Car> v;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        string s;
        int x, y;
        cin >> s >> x >> y;
        Car c(s, x, y);

        v.push_back(c);
    }

    sort(v.begin(), v.end(), compare);

    for (auto c : v)
    {
        cout << "Car :" << c.name << " " << c.x << "," << c.y << "\n";
    }

    return 0;
}
