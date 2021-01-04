#include<ADUC841.h>
#include <absacc.h>		// to access DBYTE
#include<stdio.h>	   // for display string
#include<intrins.h>

void interpreting_cmd();
void Micro10Delay(unsigned int);
void MiliDelay(unsigned int itime);

sbit LED=P3^4;
sbit fe=P3^5;

void MiliDelay(unsigned int itime)		 // 1 mili second DELAY FUNCTION 
{
unsigned int a,b;
for(a=0;a<itime;a++)
for (b=0;b<1182;b++) ;
}  
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
		interpreting_cmd(); // go to command interpreting function
  	}
}
void interpreting_cmd()
{
		switch (rx)
		{	 
 	   		case '0':
			LED = LED || 1;	
			MiliDelay(2999);						   
            Micro10Delay(99);
            fe = fe || 1; 
            Micro10Delay(1);                       // Call delay routine
            LED =LED && 0;
			fe =fe && 0;  
			break;

			case '1':
			LED = LED && 0;
			fe = fe && 0; 
			break;
		}  // end of "switch (rx)"
	
}// end of  "interpreting_cmd()" function
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
LED = fe = 0; 
for(;;)	
{
}

}