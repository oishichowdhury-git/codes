/* THIS IS A menu dtiven PROGRAM TO i.	 Print prime number
ii.	Write a program to check leap year
iii.	WAP to generate the sum of entered digits.
iv.	WAP to reverse number.
PROGRAMMER NAME - OISHI CHOWDHURY
PRN - 14070121366 */
#include<stdio.h>
#include<conio.h>
int pr(int n)
{
     int i,j=0;
     for(i=2;i<n;i++)
     {
           if(n%i==0)
           j++;
     }
     return j;
}
void year()
{
   int no;
   printf("\n\nEnter the year    ");
   scanf("%d",&no);
   if(no%4==0)
   printf("\n\n It is a leap year");
   else
   printf("\n\n It is not a leap year");   
}
int sum(int no)
{
    int p=0;
     while(no>0)
    {
          p+=no%10;
          no=no/10;
    }
  return p;  
}
void rev(int n)
{
        while(n>0)
        {
            printf("%d",n%10);
            n=n/10;
        }
}
void main()
{ 
     int ch,no,p;
     printf("Please enter the choice out of -\n\n1. Print prime number\n\n2.To check leap year\n\n3. to generate the sum of entered digits\n\n4.");
     printf("to reverse a number\t"); 
     scanf("%d",&ch);
     switch(ch)
     {
               case 1:printf("\n\nWelcome to find if the number is prime");
                      printf("\n\nEnter the number    ");
                      scanf("%d",&no);
                      p=pr(no);
                      if(p==0)
                      printf("\n\n The number is prime");
                      else
                      printf("\n\n The number is even");
                      break;
               case 2:printf("\n\nWelcome to find if it is a leap year");
                      year();
                      break;   
               case 3:printf("\n\nWelcome to generate the sum of entered digits");
                      printf("\n\nEnter the number    ");
                      scanf("%d",&no);
                      p=sum(no);
                      printf("\n\n The sum is%d",p);
                      break;
               case 4:printf("\n\nWelcome to reverse a number\t");
                      printf("\n\nEnter the number    ");
                      scanf("%d",&no);
                      rev(no);
                      break;
               default: printf("Please enter a propper choice");
     }
getch();
}
