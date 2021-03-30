#include<stdio.h>

#define MAXLINE 1000

char *any(char s1[], char s2[])
{
    int i, j, match=0;
    char rt_[2] = {'-','1'};
    char *pt= rt_;
    for (i = 0; s1[i] != '\0'; i++)
    {
        for (j = 0; s2[j] != '\0'; j++)
        {
            if(s1[i] == s2[j])
            match++;
        }
        if (match > 0)
        {
            return &s1[i];
        }
    }   
    return pt;
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
    printf("here is the address pt. for second string in s1- %s \n", any(s1, s2));
    return 0;
}