/* THIS IS  PROGRAM TO calculate area and perimeter of a circle using pointer
PROGRAMMER NAME - OISHI CHOWDHURY
PRN - 14070121366 */
#include<stdio.h>
#include<conio.h>
void sum(int*d,int *e,int *f)
{
    *f=(*d)+(*e); 
}
void main()
{
     int a,b,s=0;
     printf("Enter two numbers ");
     scanf("%d%d",&a,&b);
     sum(&a,&b,&s);
     printf("\n\nThe sum is %d",s);
     getch();
}
