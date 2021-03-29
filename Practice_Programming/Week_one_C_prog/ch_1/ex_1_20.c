#include<stdio.h>

void main()
{
    char c;
    int i, count_space=0, count_tab, sp;
    while((c = getchar()) != EOF) {
        
        if(c == ' ') {
            while((c = getchar()) == ' ')
            count_space++;    
            count_tab = count_space/4;
            sp = count_space%4;
            while(count_tab)
            {
                putchar('\t');
                count_tab--;
            }
            while(sp)
            {
                putchar(' ');
                sp--;
            }
        } 
        else
            putchar(c);
    }
   
}