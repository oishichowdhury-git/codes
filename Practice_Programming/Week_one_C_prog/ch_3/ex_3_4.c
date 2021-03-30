#include<stdio.h>
#include<string.h>
#define MAXLINE 1000

void reverse(char s[])
{
    int c, i, j;
    for (i = 0, j = strlen(s)-1; i < j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}
void itoa(int n, char s[])
{
    int i, sign;
    if ((sign = n) < 0) /* record sign */
        n = -n;
    /* make n positive */
    i = 0;
    do {
        /* generate digits in reverse order */
        s[i++] = n % 10 + '0'; /* get next digit */
    } while ((n /= 10) > 0);
    /* delete it */
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}
int main(void)
{
    int no;
    char s[MAXLINE];
    
    no = -2099999999;
    
    printf("Integer : %d \n",no);
    itoa(no,s);
    printf("Converted to string : %s\n",s);

    return 0;
}