#include <stdio.h>
 
//function to print fibonacii series
int getFibonacii(int a, int b, int n)
{   
    int sum;
    if (n>0)
    {
        printf("%d", a);
        sum = a + b;
        a = b;
        b = sum;   
        getFibonacii(a, b, n - 1);
    }
}
int main()
{
    int n;
    printf("Enter total number of terms: ");
    scanf("%d",&n);
    getFibonacii(0, 1, n);
    getchar(); 
    return 0;
}