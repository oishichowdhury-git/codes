#include<stdio.h>
#include <string.h>
void main()
{
    char ch;
    int i =0, blank_count =0, tab_count=0, newline_count=0;
    printf("enter the string");
    while((ch = getchar()) != EOF)// ctrl+d at end (for eof)
    {
        if(ch==' ')
            blank_count++;
            else if(ch=='\t')
                    tab_count++;
                    else if(ch=='\n')
                            newline_count++;
    }
    printf("\nNo of blanks = %d\n No of tabs = %d\n No of newlines = %d\n ", blank_count, tab_count, newline_count);
}