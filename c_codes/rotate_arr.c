#include<stdio.h>
int main()
{
    int n, x,i, j, arr[20], temp;
    printf("Enter length of the array");
    scanf("%d", &n);
    printf("\nEnter no of rotations");
    scanf("%d", &x);
    printf("\n Enter elements of the array");
    for(i=0; i<n; i++)
    {
        scanf("%d", &arr[i]);
    }
    //to rotate
    for(j=0; j<x; j++)
    {
        temp = arr[n-1];
        for(i=n-1; i>0; i--)
        {
            arr[i]=arr[i-1];
        }
        arr[0]=temp;
    }
    //print
    for(i=0; i<n; i++)
    {
        printf("%d", arr[i]);
    }
    return 0;
}