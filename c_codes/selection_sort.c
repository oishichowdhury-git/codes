#include<stdio.h>

void sort (int arr[], int n)
{
    int temp;
    for (int i = 0; i < n - 1; i++)
    {
        int min = i;
 
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min])
                min = j;   
        }
        temp = arr[min];
        arr[min] = arr[i];
        arr[i] = temp;
    }
}

int main()
{
    int a[10],n,i;
    printf("enter array size  ");
    scanf("%d", &n);

    printf("enter elements");
    for(i=0; i<n;i++)
    scanf("%d", &a[i]);

    sort(a, n);

    for(i=0; i<n;i++)
    printf("\n %d", a[i]);

    return 0;
}