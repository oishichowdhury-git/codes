#include<stdio.h>
void main()
{
    char ch;
    while((ch = getchar()) != EOF)// ctrl+d at end (for eof)
    {
        if(ch == ' ' || ch == '\t' || ch =='\n' || ch ==';' || ch ==':') 
                putchar('\n');   
        else
            putchar('*');
    }
}