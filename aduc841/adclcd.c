#include<stdio.h>
#include<aduc841.h>
#include<math.h>
void MiliDelay(unsigned int itime)	;
void cmdwrt(char com) ;
void datawrt(char x);

void MiliDelay(unsigned int itime)		 // 1 mili second DELAY FUNCTION 
{
unsigned int a,b;
for(a=0;a<itime;a++)
{
for (b=0;b<1182;b++) ;
}
} 
/*
void delay()
{
long i;
for(i=0;i<2000;i++)
{}
}
*/
void cmdwrt(char com)
{
	P2=com; // write command to P0 ,data lines are at P0
	P3=0x01;
	//P3.1=0 for RS=0 for command
	//P3.0=1 for E=1 to 0 for high to low pulse
	delay(50);
	P3=0x00;
	delay(50); // to give lcd some time
}

void datawrt(char x)
{
   P2=x; // write data to P2 ,data lines are at P2
   P3=0x03;
   //P3.1=1 for RS=1 for data 
   //P3.0=1 for E=1 to 0 for high to low pulse
   delay(50);
   P3=0x02;
   delay(50); // to give lcd some time
}

void main(void)
{

  int i,j[4];
  long d,h;
  double l;

  T3CON=0x084;    //	to configure
  T3FD= 0x2D;   	//	 to baudrate 38400                                     
  SCON= 0x050;	  // enable serial transmission

  ADCCON1=0x8E;	   // configure adc
  ADCCON2=0x00 ;   // configure adc
             	
  EADC = 1;	 	// To enable ADC
  
  cmdwrt(0x38);
  cmdwrt(0x0E);
  cmdwrt(0x01);
  cmdwrt(0x06);
  cmdwrt(0x80);

  while(1)
  {
   SCONV =1;  		  // for single conversion

   while(SCONV);

  d = ((0x0F & ADCDATAH)<<8)+ADCDATAL;

  for(i=0;i<4;i++)
  {
    j[i]=d%10;
    d=d/10;
  }					
  
	for(i=3;i>-1;i--)
     {
       datawrt(j[i]+48);
     } 
	datawrt('V');
    cmdwrt(0x80);
  }
  
}
