#include <iostream>

using namespace std;

int firstOcc(int a[], int s, int e, int key)
{
    if (s == e)
    {
        if (a[s] != key)
        {
            return -1;
        }
        else
            return e - 1;
    }
    else
    {
        if (a[s] == key)
        {
            return s;
        }
        else
        {
            return firstOcc(a, s + 1, e, key);
        }
    }
}

// first way
int lastOcc(int a[], int s, int e, int key)
{
    if (s == e)
    {
        if (a[s] != key)
        {
            return -1;
        }
        else
            return 0;
    }

    if (a[e - 1] == key)
    {
        return e - 1;
    }
    else
    {
        return lastOcc(a, s, e - 1, key);
    }
}

// second way
int lastOcc2(int a[], int s, int e, int key)
{
    int j = -1;
    int i = -1;
    if (s == e)
    {
        return -1;
    }
    else
    {
        i = lastOcc2(a, s + 1, e, key);
        if (a[s] == key)
        {
            j = s;
        }
    }
    if (i < j)
    {
        return j;
    }
    else
    {
        return i;
    }
}

void allOcc(int a[], int s, int e, int key)
{
    if (s == e)
    {
        return;
    }
    else
    {
        if (a[s] == key)
        {
            cout << s << " ";
        }
        allOcc(a, s + 1, e, key);
    }
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 7, 6, 7, 10};
    int key = 7;
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Last Occ: ";
    allOcc(arr, 0, n, key);
}