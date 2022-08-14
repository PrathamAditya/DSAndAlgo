/**
 * author: adityapratham
 **/
#include <bits/stdc++.h>

using namespace std;

void strtokk(char a[], char delim)
{
    int i = 0;
    while (a[i] != '\0')
    {
        if (a[i] == delim)
        {
            cout << "\n";
        }
        else
        {
            cout << a[i];
        }
        i++;
    }
}
char *mystrtok(char *s, char delim)
{
    // state of the static variable is insial once
    static char *input = NULL;
    if (s != NULL)
    {
        input = s;
    }

    // start extracting tokens and store them in array
    // we do this in dynamically
    // cuz we wnt this array to exist even after the function call

    char *output = new char[strlen(input) + 1];
}

int main()
{
    char s[100] = "Today, is a rainy, day";
    strtokk(s, ',');

    return 0;
}