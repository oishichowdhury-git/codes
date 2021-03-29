#include <stdio.h>
#define MAX_SIZE 100

int main()
{

    int i, pos, ele, arr[] = {5, 6, 7, 8, 9, 8, 0} ;   
    printf("enter ele to find\n");
    scanf( "%d", &ele);
    for (i=0;i<7;i++)
    {
        if(arr[i]==ele)
        printf(" found at %d\n", i);
    }

    return 0;
}