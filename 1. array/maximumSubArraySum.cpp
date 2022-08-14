#include <iostream>

using namespace std;

void MaxSubSum1(int a[], int n)
{
    int left = -1;
    int right = -1;
    int maxSum = -INT_MAX;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            int currentSum = 0;
            for (int k = i; k <= j; k++)
            {
                currentSum = currentSum + a[k];
            }
            if (currentSum > maxSum)
            {
                maxSum = currentSum;
                left = i;
                right = j;
            }
        }
    }
    cout << "The Max Sub Sum: " << maxSum << "\n";
    for (int i = left; i <= right; i++)
    {
        cout << a[i] << ", ";
    }
}

void MaxSubSum2(int a[], int n)
{
    int b[n] = {0};
    for (int i = 0; i < n; i++)
    {
        if (i > 0)
        {
            b[i] = a[i] + b[i - 1];
        }
        else
        {
            b[i] = a[i];
        }
    }
    int r = -1;
    int l = -1;
    int maxSum = 0;
    int currentSum = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            currentSum = b[j] - b[i - 1];
            if (currentSum > maxSum)
            {
                maxSum = currentSum;
                l = i;
                r = j;
            }
        }
    }
    cout << "maxSum: " << maxSum << "\n";
}

// Kadane's Algo
void MaxSubSum3(int a[], int n)
{
    int currentSum = 0;
    int maxSum = 0;
    // int l = 0;
    // int r = 0;

    for (int i = 0; i < n; i++)
    {
        currentSum = currentSum + a[i];
        if (currentSum < 0)
        {
            currentSum = 0;
            // l = i + 1;
        }

        if (maxSum < currentSum)
        {
            maxSum = currentSum;
            // r = i;
        }

        maxSum = max(maxSum, currentSum);
    }
    cout << "maxSum: " << maxSum << "\n";
    // cout << r << " " << l << "\n";
}

int main()
{
    int n;
    cout << "Enter n: ";
    cin >> n;

    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << "\n";
    MaxSubSum3(a, n);
}