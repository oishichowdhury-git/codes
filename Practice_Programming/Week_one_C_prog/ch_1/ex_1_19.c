#include<stdio.h>
#define MAXLINE 1000
int get_line(char s[],int lim)
{
    int c, i;

    for (i=0; i < lim-1 && (c = getchar())!=EOF && c!='\n'; ++i)
        s[i] = c;
    
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

int main()
{
    int len, i, j;
    char line[MAXLINE], rev_line[MAXLINE];

    while ((len = get_line(line, MAXLINE)) > 0){
        j = len -1;
       for (i = 0; i < len; i++){
            rev_line[i] = line[j];
            j--;
        } 
        printf("%s", rev_line);
    }
    return 0;
}