#include <stdio.h>
#define MAX_SIZE 100

int main()
{

    int i, pos, ele, arr[] = {5, 6, 7, 8, 9, 8, 0} ;   
    printf("enter ele n poss\n");
    scanf("%d %d", &ele, &pos);
    for(i=7; i>pos; i--)
    {
        arr[i] = arr[i-1];
    }
    arr[pos]= ele;
    for (i=0;i<7;i++)
    {
        printf("%d", arr[i]);
    }

    return 0;
}