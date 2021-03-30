#include<stdio.h>
#include<limits.h>
int main()
{
    printf("Here are the ranges - \n");
    printf("char- %d to %d\n",CHAR_MIN,CHAR_MAX);
    printf("short- %d to %d\n",SHRT_MIN,SHRT_MAX);
    printf("int- %d to %d\n",INT_MIN,INT_MAX);
    printf("long- %ld to %ld\n",LONG_MIN,LONG_MAX);

    printf("signed char- %d to %d\n",SCHAR_MIN,SCHAR_MAX);

    printf("unsigned char- %d to %d\n",0,UCHAR_MAX);
    printf("unsigned int- %d to %u\n",0,UINT_MAX);
    printf("unsigned long- %d to %lu\n",0,ULONG_MAX);
    return 0;
}