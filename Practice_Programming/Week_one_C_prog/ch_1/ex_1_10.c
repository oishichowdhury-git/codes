#include<stdio.h>
void main()
{
    char ch;
    printf("enter the string");
    while((ch = getchar()) != EOF)// ctrl+d at end (for eof)
    {
        if(ch==' ')
            {
                putchar('\\');
                putchar('b');
            }
        if(ch=='\t')
            {
                putchar('\\');
                putchar('t');
            }
        if(ch=='\n')
            {
                putchar('\\');
                putchar('n');
            }
        if(ch=='\\')
            {
                putchar('\\');
                putchar('\\');
            }
        else
            putchar(ch);
    }
}