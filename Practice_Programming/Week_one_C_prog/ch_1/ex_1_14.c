#include<stdio.h>
void main()
{
    char ch, ar[26], AR[26];
    int i, his[26];
    ar[0]='a';
    AR[0]='A';
    for(i=1;i<26;i++)
    {
        ar[i] = ar[i-1]++;
        AR[i] = AR[i-1]++;
        his[i] = 0;
    }
    printf("Histogram\n");
    while((ch = getchar()) != EOF)// ctrl+d at end (for eof)
    {
        for(i=0;i<26;i++)
        {
            if((ch == ar[i]) || (ch == AR[i]))
            his[i]++;
        }
    }
    for(i=0;i<26;i++)
    {
        if(his[i] > 0)
        printf("%c - %d\n", ar[i], his[i]);
    }
}