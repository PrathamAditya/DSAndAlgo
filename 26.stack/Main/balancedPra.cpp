/**
 * author: adityapratham
 **/
#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool isBal(string s)
{
    stack<char> ss;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[')
        {
            ss.push(s[i]);
        }
        else if (s[i] == ')' || s[i] == '}' || s[i] == ']')
        {
            if (ss.top() == '(' and s[i] == ')')
            {
                ss.pop();
            }
            if (ss.top() == '{' and s[i] == '}')
            {
                ss.pop();
            }
            if (ss.top() == '[' and s[i] == ']')
            {
                ss.pop();
            }
        }
    }
    return ss.size() == 0;
}

int main()
{

    string s = "[{(a+b) + (b+c)} * {a-a]";
    cout << isBal(s);
    return 0;
}