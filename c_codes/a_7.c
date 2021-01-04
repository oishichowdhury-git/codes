/* THIS IS  PROGRAM TO calculate area and perimeter of a circle using pointer
PROGRAMMER NAME - OISHI CHOWDHURY
PRN - 14070121366 */
#include<stdio.h>
#include<conio.h>
void main()
{
     float r,ar,per,*ra;
     printf("enter the radius ");
     scanf("%f",&r);
     ra=&r;
     per=(*ra)*2*3.14;
     ar=3.14*(*ra)*(*ra);
     printf("\n\nThe area is %f",ar);
     printf("\n\nThe perimerer is %f",per);
     getch();
}
