#include<stdio.h>

int store[];

int fibb(int n)
{   

    if (n<0)
    return -1;
    else{
         if (store[n] !=0)
        else
        {
            store[n] = fibb (n-2) + fibb(n-1);
        }
        return store[n];
    }

}

int main()
{
    int n, fibb_no;
    store[0]=0;
    store[1]=1;
    printf("Enter n for nth number of fibbonaci ser");
    scanf("%d", &n);
    fibb_no = fibb(n);
    printf ("%d is the fibbonacci no required", fibb_no);
    return 0;
}