// ACVM code
// Name- Oishi Chowdhury
// PRN- 14070121366

# include<LPC21xx.h>
int i;

void tx(char x)
{   
    while(!(U0LSR & 0X20));
    U0THR= x;
}

char rxint()
{
	   char r;
	   int a;
     while (!(U0LSR & 0X01));
	   r= U0RBR;
	   if(r=='1')
			 a=1;
		 else if(r=='2')
			 a=2;
	   return a;
}
char rxchar()
{
	   char r;
	   while (!(U0LSR & 0X01));
	   r= U0RBR;
	   return r;
}
int choice()
{
	int ch;
	char r;
	r=rxchar();
	if(r=='a')
		ch=1;
	if(r=='b')
		ch=2;
	if(r=='c')
		ch=3;
	tx(r);
	return ch;
}
int check_coins()
{
   int c[3], sum=0,ch,ret;
   char falero[15]={"Falero is out  "};
   char eclairs[16]={"Eclairs is out "};
   char polo[13]={"Polo is out  "};
   char enter[]={"\nEnter coins\n"};
   ch=choice();
   for(i=0;i<13;i++)
      tx(enter[i]);
   for(i=0;i<3;i++)
    {
			 c[i]=rxint();
			 sum= sum+c[i];
    }
		ret= sum-ch;
    if (ch==1)
		{
			  for(i=0;i<15;i++)
           {
               tx(falero[i]);
            }
    }
		else if(ch==2)
		{   
			for(i=0;i<16;i++)
           {
               tx(eclairs[i]);
            }			
    }
		else if(ch==3)
		{
			  for(i=0;i<13;i++)
           {
               tx(polo[i]);
            }
    }
    return ret; 
}

void delay()
{
    long j;
    for(j=0;j<10000000;j++)
     for(i=0;i<200;i++)
     {
     }
}

void display_menu()
{
    char menu[]={"Welcome kid,\n Options for you-\na. Falero- one rupee\nb. Eclairs- two rupees\nc. Polo- three rupees\n  "};
    for(i=0;i<100;i++) 
    tx(menu[i]);
}

void main()
{
    int c,t=1;
    char encn[]={"\nThe amount returned is  "};
    char ty[]={" \nThank you my dear  "};
    PINSEL0=0X00000005;

    U0LCR=0X9B;
    U0DLM=0X62;
    U0LCR=0X1B;

    display_menu();

        c=check_coins();
        if (c>0)
        {
         for(i=0;i<25;i++)
         {
            tx(encn[i]);
         }	
         tx(c+48);
				 tx('r');
				 tx('s');
        }
    for(i=0;i<21;i++)
    {
        tx(ty[i]);
    }
}
