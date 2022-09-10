#include <iostream>
#include <queue>

using namespace std;

int main()
{
    queue<char> q;
    int freq[27] = {0};
    char ch;
    while (ch != '.')
    {
        cin >> ch;
        q.push(ch);
        freq[ch - 'a']++;

        while (!q.empty())
        {
            if (freq[q.front() - 'a'] > 1)
            {
                q.pop();
            }
            else
            {
                cout << q.front() << " ";
                break;
            }
        }
        if (q.empty())
        {
            cout << "-1"
                 << " ";
        }
    }
}