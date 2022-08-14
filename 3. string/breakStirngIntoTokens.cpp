#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    char s[100] = "Today is a rainy day";
    char *ptr = strtok(s, " ");
    cout << ptr << "\n";

    while (ptr != NULL)
    {
        ptr = strtok(NULL, " ");
        cout << ptr << "\n";
    }
}