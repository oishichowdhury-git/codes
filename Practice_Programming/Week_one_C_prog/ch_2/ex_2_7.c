#include<stdio.h>
#include<math.h>

int invert(int x, int p, int n)
{
    int mask = pow(2,p);
    int inv_part = ~(x & (~mask));
    x = x & mask;
    x = x | inv_part;
    return x;
}

int main()
{
    printf("%d",invert(4444, 11, 4));
    return 0;
}