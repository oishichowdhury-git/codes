#include<stdio.h>

int arr[10] = {0,1,2,3,4,5,6,7,8,9};
int main()
{
    int low, mid, high;
    low = 0;
    high = 9;
    int ele = 6;
    while(high>low)
    {
        mid = (low + high)/2;
        if(ele>arr[mid])
            low = mid+1;
        else
            high = mid;
        
        if(ele == arr[mid])
            printf("element at pos %d", mid);  
    }
    printf("\n done");
}