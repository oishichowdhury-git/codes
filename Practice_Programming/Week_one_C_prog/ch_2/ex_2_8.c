#include<stdio.h>

unsigned rightrot(unsigned x,int n)
{
    unsigned y = x ;
    int i, len, r_shift;
    for(i=0; y>0; i++)
    {
        y = y>>1;
    }
    len = i;
    r_shift = x << (len - n);
    x = x >> n;
    x = x | r_shift;
    return x;
}

int main()
{
    printf(" %u rightshifted %d times to get %u", 444, 5, rightrot(444, 5));
    return 0;
}