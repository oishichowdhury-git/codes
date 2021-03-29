#include<stdio.h>
void main()
{
    char ch;
    int wc = 1;
    while((ch = getchar()) != EOF)
    {
        if(ch == ' ' || ch == '\t' || ch =='\n' || ch ==';' || ch ==':') 
            wc++;
            // corner cases can be 
            //"wasn't" - 2 words or 1 word
            //abc>999 - 2 words
            //replace '>' with any mathematical operation 
    }
    printf("No. of words - %d", wc);
}