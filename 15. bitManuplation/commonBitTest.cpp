#include <iostream>

using namespace std;

bool isOdd(int n)
{
    return n & 1;
}

bool getBit(int n, int i)
{
    int mask = (1 << i);
    int bit = (n & mask) > 0 ? 1 : 0;
    return bit;
}

int setBit(int n, int i)
{
    int mask = (1 << i);
    int ans = (n | mask);
    return ans;
}

int clearBit(int n, int i)
{
    int mask = ~(1 << i);
    int ans = n and mask;
    return ans;
}
int updateBit(int n, int i, int v)
{
    int a = clearBit(n, i);
    a = a | (v << i);
    return a;
}
// clear range of bits

int clearLastIBits(int n, int i)
{
    int mask = (-1 << i);
    return n & mask;
}

int main()
{
    int n = 15;
    // the number of bits that ar getting cleared
    int i = 3;
    cout << clearLastIBits(15, 3);
}