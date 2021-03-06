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
void itob(int n,char s[],int w)
{
    int i=0, dig, sign;

    if((sign=n)<0)
        n = -n;
    while(n>0)
    {
        dig = n%10;
        s[i++]= dig<10? dig + '0': dig + 'a' - 10;
        n/=10;
    }
    if(sign < 0)
        s[i++]='-';    
    while(i<w)
        s[i++]=' ';

    s[i]='\0';
    reverse(s);
}
int main(void)
{
    int no;
    char s[MAXLINE];
    
    no = -1234;
    
    printf("Integer : %d \n",no);
    itob(no,s,10);
    printf("Converted to string : %s\n",s);

    return 0;
}