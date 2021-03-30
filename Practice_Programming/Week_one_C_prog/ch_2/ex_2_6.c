#include<stdio.h>
#include<math.h>

int setbits(int x, int p, int n, int y)
{
    int mask = pow(2,p);
    x = x & (~mask);
    y = y & mask;
    y = y | x;
    return y;
}

int main()
{
    printf("%d",setbits(4444, 11, 4, 5555));
    return 0;
}