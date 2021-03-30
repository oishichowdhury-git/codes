#include<stdio.h>
#define MAXLINE 1000
int get_line(char s[],int lim)
{
    int c, i = 0;
    while( i < lim -1 )
    {
        if((c = getchar())!=EOF)
        {
            if(c!='\n')
                ++i;
                s[i] = c;
        }
    }
    
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

int main()
{
    int len;
    char line[MAXLINE];

    while ((len = get_line(line, MAXLINE)) > 0){
        printf("%s", line);
    }
    return 0;
}