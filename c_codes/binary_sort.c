#include<stdio.h>

struct Node {
    int data;
    struct Node* next;
};

void sort(int a[], int n)
{
    int temp;
    for(int j=0;j<n-1;j++)
    {
        for (int i=0; i<n-1;i++)
        {
            if(a[i]>a[i+1])
            {
                temp = a[i];
                a[i] = a[i+1];
                a[i+1] = temp;
            }
        }
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