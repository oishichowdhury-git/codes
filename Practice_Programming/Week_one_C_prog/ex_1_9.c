#include<stdio.h>
void main()
{
    char ch, prev_ch=0;
    printf("enter the string");
    while((ch = getchar()) != EOF)// ctrl+d at end (for eof)
    {
        if(ch==' ')
            {
                if(prev_ch!=' ')
                    putchar(ch);
            }
        else
            putchar(ch);
        prev_ch = ch;
    }
}