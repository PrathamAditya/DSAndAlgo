#include <iostream>
#include <algorithm>

using namespace std;

void BubbleSort(int A[], int n)
{
    if (n == 1)
    {
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (A[i] > A[i + 1])
        {
            swap(A[i], A[i + 1]);
        }
    }
    BubbleSort(A, n - 1);
}

void bubbleSortRecursive(int A[], int n, int j)
{
    if (n == 1)
    {
        return;
    }
    if (j < n - 1)
    {
        if (A[j] > A[j + 1])
        {
            swap(A[j], A[j + 1]);
        }
        bubbleSortRecursive(A, n, j + 1);
    }
    else
    {
        bubbleSortRecursive(A, n - 1, 0);
    }
}

int main()
{
    int A[] = {5,
               4,
               3,
               2,
               1};
    int n = 5;

    cout << "Before Sorting: ";
    for (int i = 0; i < n; i++)
    {
        cout << A[i] << " ";
    }
    cout << "\n";

    bubbleSortRecursive(A, n, 0);
    cout << "After Sorting: ";
    for (int i = 0; i < n; i++)
    {
        cout << A[i] << " ";
    }

    return 0;
}