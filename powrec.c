#include <stdio.h>
 
//function to print fibonacii series
int po(int a, int n)
{   
    if (n>1)
    return a*po(a, n-1);
}
int main()
{
    int a,n;
    printf("Enter a , n for a pow n ");
    scanf("%d%d",&a,&n);
    printf("%d",po(a, n));
    getchar(); 
    return 0;
}