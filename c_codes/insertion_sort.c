#include<stdio.h>

void sort(int arr[10], int n)
{
     for (int i = 1; i < n; i++)
    {
        int value = arr[i];
        int j = i;
 
        // Find the index j within the sorted subset arr[0..i-1]
        // where element arr[i] belongs
        while (j > 0 && arr[j - 1] > value)
        {
            arr[j] = arr[j - 1];
            j--;
        }
 
        // Note that subarray arr[j..i-1] is shifted to
        // the right by one position i.e. arr[j+1..i]
 
        arr[j] = value;
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