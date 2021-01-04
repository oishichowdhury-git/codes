/* THIS IS A PROGRAM TO print a pattern- descending 1 to 5
PROGRAMMER NAME - OISHI CHOWDHURY
PRN - 14070121366 */
#include<stdio.h>
#include<conio.h>
void main()
{

     int i,j;
     for(i=5;i>0;i--)
     {
         for(j=1;j<=i;j++)
         printf("%d",j);
         printf("\n");
     }
     getch();
}
