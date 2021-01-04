/* THIS IS A menu dtiven PROGRAM TO perform following Matrix operations
1.	Matrix addition
2.	Matrix Multiplication
3.	Matrix transpose

PROGRAMMER NAME - OISHI CHOWDHURY
PRN - 14070121366 */
#include<stdio.h>
#include<conio.h>
void display(int c[10][10],int m, int n)
{
     int i=0,j=0;
     for(i=0;i<m;i++)
     {
      for(j=0;j<n;j++)
      printf("%d ",c[i][j]);
      printf("\n");
     }
}
void main()
{
     int m,n,p,q,i,j,k, a[10][10],b[10][10],c[10][10];
     printf("\nEnter size of a   ");
     scanf("%d%d",&m,&n);
     printf("\nEnter elements in a  ");
     for(i=0;i<m;i++)
     for(j=0;j<n;j++)
     scanf("%d",&a[i][j]);
     
     printf("Enter the choice out of- \n1.Matrix addition\n\n2.Matrix Multiplication\n\n3.Matrix transpose  ");
     scanf("%d",&k);
     switch(k)
     {
              case 1:printf("\nEnter size of b   ");
                     scanf("%d%d",&p,&q);
                     printf("\nEnter elements in b ");
                     for(i=0;i<p;i++)
                     for(j=0;j<q;j++)
                     scanf("%d",&b[i][j]);
                     if(m==p&&n==q)
                     {
                         for(i=0;i<m;i++)
                         for(j=0;j<n;j++)
                         c[i][j]=a[i][j]+b[i][j];
                         printf("\n\nthe sum -\n");
                     } 
                     else
                     printf("sorry not possible"); 
                     display(c,m,n);
                     break;
              case 2:printf("\nEnter size of b   ");
                     scanf("%d%d",&p,&q);
                     printf("\nEnter elements in b ");
                     for(i=0;i<p;i++)
                     for(j=0;j<q;j++)
                     scanf("%d",&b[i][j]);
                     if(n==p)
                     {
                         for(i=0;i<m;i++)
                         for(k=0;k<q;k++)
                         {    
                             c[i][k]=0;
                             for(j=0;j<n;j++)
                             c[i][k]+=a[i][j]+b[j][k];  
                         } 
                        printf("\n\nthe multiplication is -\n");  
                     }
                     else
                     printf("sorry not possible");  
                     display(c,m,q); 
                     break;
              case 3: for(i=0;i<m;i++)
                      for(j=0;j<n;j++)
                      {
                            c[j][i]=a[i][j];
                      } 
                      printf("\n\nthe transpose is -\n");  
                      display(c,n,m);
                     break;       
              default: printf("please enter proper choice");
     }
     getch();
}
