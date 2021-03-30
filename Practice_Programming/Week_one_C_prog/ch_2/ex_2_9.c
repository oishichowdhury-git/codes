#include<stdio.h>

unsigned bit_count(unsigned x)
{
   int b;
    for (b = 0; x != 0; x &= x-1)// &is faster, x=x&x-1 sets last bit to 0 ; can be used to count 1s
        b++;
    return b;
}

int main()
{
    printf(" %d is the no. of 1-bits in %u", bit_count(444), 444);
    return 0;
}