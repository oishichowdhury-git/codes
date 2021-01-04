#include<ADUC841.h>
#include <absacc.h>		// to access DBYTE
#include<stdio.h>	   // for display string
#include<intrins.h>

sbit LED=P3^4;
sbit mt=P3^5;
int x,k;
float t_10sec;
unsigned int i,j,T;
int d;
unsigned char y[3];

void del();
void Micro10Delay(unsigned int);	   // Function definition
void interpreting_cmd();
void Micro10Delay(unsigned int itime)		 // 1 mili second DELAY FUNCTION 
{
unsigned int a,b;
for(a=0;a<itime;a++)
{
for (b=0;b<5;b++) ;
}
} 
unsigned char rx;		 
//Serial Interrupt Service Routine		 

static void com_isr (void) interrupt 4 				//using 1 
{
//----- Received data interrupt. ----------------------------------------
	if (RI) 
	{
  		
		rx = SBUF; 	// read character
  		RI = 0; 	// clear interrupt request flag
		if(rx=='9')
		{
		  del();
		}
		interpreting_cmd(); // go to command interpreting function
  	}
}

void del()
{
   for(k=0;k<3;k++)
   {
   	   	while(! RI);
		{
		   rx = SBUF; 	// read character
  		   RI = 0; 	// clear interrupt request flag
		   y[k]= rx-48;
		}
		d=(y[0]+10*y[1]+100*y[2]);
		t_10sec= 100.0/d;
		T = (int)t_10sec/2;
		rx = '9';
   }
}
//--SEND CHARACTER TO PC via UART--
void transmit(unsigned char te )
{
 ES=0;
 SBUF=te;
 while(TI==0){}
 TI=0;
 ES=1;
}

void interpreting_cmd()
{
transmit(rx);
		switch (rx)
		{	 
 	   		case '1':
			LED = LED ^ 1;
			break;

			case '5':
			x=0;
			mt = mt ^ 1;
			Micro10Delay(1);
			mt = mt ^ 1;
			break;

			case '9':
			x=1;			
			break;

		}  // end of "switch (rx)"
	
}// end of  "interpreting_cmd()" function
		
	

//----------------------------------------MAIN PROGRAM--------------------------------------
void main(void) // starting of main program
{
// Serial Communication Iniialization
//--------------------------------------------------------------------------------
//Setup the serial port for 38400 baud at 11.0592MHz microcontroller clock frequency.
//--------------------------------------------------------------------------------
SCON  = 0x50;		// SCON: mode 1, 8-bit UART, enable rcvr
T3CON= 0x86;		//T3CON =0x86 for 9600; =0x85 for 19200; =0x84 for 38400 baudrates at crystal frequency of 11.0592 MHz 
T3FD=0x08;
EA = 1;					// Enable Interrupts
ES=1;

LED = LED ^ 1;
mt = mt ^ 1;

for(;;)					// Loop Forever
{  
 if(x==1)
  {     
	 mt = mt ^ 1;
	 for(i=0;i<13500;i++)
	 {
       Micro10Delay(T);
	 }
  }                      // Call delay routine

}
}
