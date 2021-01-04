/* THIS IS A PROGRAM TO print a pattern- hill of stars
PROGRAMMER NAME - OISHI CHOWDHURY
PRN - 14070121366 */
#include<stdio.h>
#include<conio.h>
void main()
{
     int i,j;
     for(i=1;i<6;i++)
     {
         for(j=5;j>i;j--)
         printf(" ");
         for(j=1;j<2*i;j++)
         printf("*");
         printf("\n");
     }
     getch();
}
