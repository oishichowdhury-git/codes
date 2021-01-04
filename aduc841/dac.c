#include<stdio.h>
#include<aduc841.h>
void MiliDelay(unsigned int itime)		 // 1 mili second DELAY FUNCTION 
{
unsigned int a,b;
for(a=0;a<itime;a++)
{
for (b=0;b<1182;b++) ;
}
} 

void main(void)
{

  T3CON=0x084;    //	to configure
  T3FD= 0x2D;   	//	 to baudrate 38400                                     
  SCON= 0x050;	  // enable serial transmission

  DACCON=0x7B;

  MiliDelay(50);
  DAC0H=0X0a;
  DAC0L=0Xa0;
  DAC1H=0X0a;
  DAC1L=0Xa0;

  DACCON=0x7F;
  MiliDelay(50);

  while(1);
}