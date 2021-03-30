#include<stdio.h>
#define MAXLINE 1000

int get_line(char s[],int lim)
{
    int c, i;

    for (i=0; i < lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
        s[i] = c;
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

char *expand(char s1[], char s2[])
{
    int i=0, j=0;
    char a;
    while(s1[i] != '\0')
    {
        i++;
        if(s1[i]=='-')
            {
                if(s1[i+1] >= s1[i-1])
                {
                    i++;
                    a = s1[i-2];
                    while(a<s1[i])
                        {
                            s2[j]=a;
                            j++;
                            a++;
                        }
                }
            }
        else 
            s2[j++]=s1[i-1];
    }
    s2[j]='\0';
    return s2;
}

int main()
{
    char s1[MAXLINE],s2[MAXLINE];
    char line[MAXLINE];
    while (get_line(line, MAXLINE) > 0){
        printf("\n %s expanded - %s",line, expand(line,s2));
    }
    return 0;
}