#include <iostream>
#include <stack>

using namespace std;

bool isVAlidExp(char *s)
{
    stack<char> c;

    for (int i = 0; s[i] != '\0'; i++)
    {
        if (s[i] == '(')
        {
            c.push('(');
        }
        if (s[i] == ')')
        {
            if (c.empty() or c.top() != '(')
            {
                return false;
            }
            c.pop();
        }
    }

    return c.empty();
}

int main()
{
    char s[100] = "((a+b) * (c-d+f)))";
    cout << isVAlidExp(s);
}