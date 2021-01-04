/* THIS IS A menu dtiven PROGRAM TO perform following string functions
 1.	String Length
2.	String Compare
3.	String copy
4.	String Concatenation

PROGRAMMER NAME - OISHI CHOWDHURY
PRN - 14070121366 */
#include<stdio.h>
#include<conio.h>
#include<string.h>

int main()
{
     int ch,t;
     char p;
     char s;
     printf("Please enter the choice to perform -\n\n1.Find String Length\n\n2.String Compare\n\n3.String copy\n\n4.String Concatenation  ");
     scanf("%d",&ch);
     printf("Please enter a word  ");
     scanf("%s",&s);
     switch(ch)
     {
            case 1:
                   printf("\n\n The length is:  %d",strlen(s));
                   break;
            case 2:printf("Please enter a word");  
                   scanf("%s",p);
                   if(strcmp(s,p)==0)
                   printf("\n\nSame ");
                   else
                   printf("\n\nNot Same ");
                   break;
            case 3:printf("Please enter a word");  
                   scanf("%s",p);  
                   strcpy(s,p);
                   printf("\n\n %s",s);
                   break;
            case 4:printf("Please enter a word");  
                   scanf("%s",p);  
                   strcat(s,p); 
                   printf("\n\n %s",s);
                   break;        
           default: printf("Please enter propper choice");         
     }
     getch();
     return 0;
}
