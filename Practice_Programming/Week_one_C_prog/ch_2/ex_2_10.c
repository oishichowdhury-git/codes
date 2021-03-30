#include<stdio.h>

int lower(int c)
{
    return ((c>='A' && c<='Z')? (c+32) : c);
}

int main(void)
{
    int c;
    
    while((c=getchar())!=EOF)
    {
        putchar(lower(c));
    }
}