#include<stdio.h>

#define MAXLINE 1000

char *new_str(char s1[], char s2[])
{
    int i, j, k=0, match;
    char s[1000];
    for (i = 0; s1[i] != '\0'; i++)
    {
        match = 0;
        for (j = 0; s[j] != '\0'; j++)
        {
            if(s1[i] == s2[j])
            match++;
        }
        if (match == 0)
        {
            s[k] = s1[i];
            k++;
        }
    }
    s1 = s;
    return s1;
}

int main()
{
    char s1[MAXLINE], s2[MAXLINE];
    int i, c;
    for (i=0; (c = getchar()) != '\n'; i++)
        s1[i] = c;
    s1[i] = '\0';
    for (i=0; (c = getchar()) != '\n'; i++)
        s2[i] = c;
    s2[i] = '\0';
    printf("%s, %s to new string %s\n", s1, s2, new_str(s1, s2));
    return 0;
}