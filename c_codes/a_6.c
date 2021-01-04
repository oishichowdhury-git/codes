/* THIS IS A menu dtiven PROGRAM TO perform following operations on 1d array of integers. 
1.	Add element
2.	Display elements
3.	Insert element
4.	Delete element
5.	Search element
6.	Sort elements

PROGRAMMER NAME - OISHI CHOWDHURY
PRN - 14070121366 */
#include<stdio.h>
#include<conio.h>
void display(int c[100],int m)
{
     int i=0;
     for(i=0;i<m;i++)
     printf("%d ",c[i]);
}
void main()
{
     int i,j,m, a[100],ele,poss;
     printf("Enter the no. of elements ");
     scanf("%d",&m);
     printf("\n\nEnter the elements ");
     for(i=0;i<m;i++)
     scanf("%d",&a[i]);
     printf("Enter choice out of - \n1.Add element\n2.Display elements\n3.Insert element\n4.Delete element\n5.Search element\n6.Sort elements  ");
     scanf("%d",&i);
     switch(i)
     {
              case 1:printf("Enter element to be added");
                     scanf("%d",&ele);
                     m++;
                     a[m-1]=ele;
                     display(a,m);
                     break;
              case 2:display(a,m);
                     break;
              case 3:printf("Enter possition where the element is to be inserted ");
                     scanf("%d",&poss); 
                     m++;
                     for(i=m-1;i>poss+1;i--)
                     a[m-1]=a[m-2];  
                     printf("Enter element to be inserted ");
                     scanf("%d",&a[poss]);
                     display(a,m);
                     break;
              case 4:printf("Enter possition where the element is to be deleted ");
                     scanf("%d",&poss);
                     for(i=poss;i<m-1;i++)
                     a[i]=a[i+1];
                     m--;
                     display(a,m);
                     break; 
              case 5:printf("Enter which element is to be searched ");
                     scanf("%d",&ele);
                     for(i=0;i<m;i++)
                     {
                            if(a[i]==ele)
                            printf(" element found at possition %d ",i);       
                     }
                     break;
              case 6:printf("\nSorted array -\n");
                     for(i=0;i<m-1;i++)
                     for(j=0;j<m-1;j++)
                     {
                         if(a[j]>=a[j+1])
                         {
                             ele=a[j];
                             a[j]=a[j+1];
                             a[j+1]=ele;
                         }
                     }
                     display(a,m);
                     break;
              default: printf("enter propper choice");      
     }
     getch();
}
