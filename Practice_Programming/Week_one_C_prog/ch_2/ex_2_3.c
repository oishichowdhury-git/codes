#include<stdio.h>
#include<math.h>
#define MAXLINE 1000
// assume 0x not present
int hoti(char s[])
{
    int conv=0, i, n=0;
    char c;
    for (i = 0; (c = s[i]) != '\0'; i++)
    {
        conv*= 16;
        if (c >= '0' && c <= '9')
        {
            n = c - '0';
        }
        else if (c >= 'a' && c <= 'f')
            {
                n = 10 + c - 'a';
            }
            else if (c >= 'A' && c <= 'F')
                {
                    n = 10 + c - 'A';
                }
        conv+= n;
    }
    return conv;
}

int main()
{
    char s[MAXLINE];
    int i, c;
    for (i=0; (c = getchar()) != '\n'; i++)
        s[i] = c;
    s[i] = '\0';
    printf("0x%s is to integer %d\n", s, hoti(s));
    return 0;
}
