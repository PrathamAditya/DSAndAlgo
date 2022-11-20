// #include <iostream>
// using namespace std;
// class Base
// {
// public:
//     Base()
//     {
//         cout << "Constructing Base \n";
//     }
//     ~Base()
//     {
//         cout << "Destructing Base \n";
//     }
// };
// class Derived : public Base
// {
// public:
//     Derived()
//     {
//         cout << "Constructing Derived \n";
//     }
//     ~Derived()
//     {
//         cout << "Destructing Derived \n";
//     }
// };

// int main(void)
// {
//     Derived *d = new Derived();
//     Base *b = d;
//     delete b;
//     return 0;
// }

// #include <iostream>

// using namespace std;

// void Execute(int &x, int y = 200)
// {
//     int TEMP = x + y;
//     x += TEMP;
//     if (y != 200)
//         cout << "-";
// }

// int main()
// {
//     // int A = 50, B = 20;
//     // Execute(A, B);
//     int len;
//     char str1[] = {"39 march road"};
//     len = strlen(str1);
//     cout << len << "\n";
// }

/**
 * author: adityapratham
 **/
// #include <iostream>

// using namespace std;

// int main(){
//     return 0;
// }

/**
 * author: adityapratham
 **/
#include <iostream>

using namespace std;

void printSubStr(string str, int low, int high)
{
    for (int i = low; i <= high; ++i)
        cout << str[i];
}

int longestPalSubstr(string str)
{
    int n = str.size();

    int maxLength = 1, start = 0;

    for (int i = 0; i < str.length(); i++)
    {
        for (int j = i; j < str.length(); j++)
        {
            int flag = 1;

            for (int k = 0; k < (j - i + 1) / 2; k++)
                if (str[i + k] != str[j - k])
                    flag = 0;

            if (flag && (j - i + 1) > maxLength)
            {
                start = i;
                maxLength = j - i + 1;
            }
        }
    }

    cout << "Longest palindrome substring is: ";
    printSubStr(str, start, start + maxLength - 1);

    return maxLength;
}

int main()
{
    string str = "forgeeksskeegfor";
    cout << "\nLength is: "
         << longestPalSubstr(str);
    return 0;
}