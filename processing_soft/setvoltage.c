#include<ADUC841.h>
#include <absacc.h>		// to access DBYTE
#include<stdio.h>	   // for display string
#include<intrins.h>
#include<math.h>

void interpreting_cmd();
void transmit(unsigned char te );

int i,x,presetv,finalsetv,sv[4],k;
char rx,j[4];
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
		switch (rx)
		{
		 	case '5':
			x=5;
			presetv=0;
			finalsetv=0;
			for(i=0;i<4;i++)
			{
				while(!RI);
				sv[i]=SBUF;
				RI=0;
				presetv = presetv*10 + (sv[i]-48);
			}
			for(i=3;i>-1;i--)
			{
				j[i]= setv%10;
				finalsetv = finalsetv*10 + j[i];
				presetv = presetv /10;
			   	transmit(j[i]+48);
			}
			break;

		    default:  x=3;
		}
}
void main(void) // starting of main program
{
// Serial Communication Iniialization
//--------------------------------------------------------------------------------
//Setup the serial port for 38400 baud at 11.0592MHz microcontroller clock frequency.
//--------------------------------------------------------------------------------
SCON  = 0x50;		// SCON: mode 1, 8-bit UART, enable rcvr
T3CON= 0x84;		//T3CON =0x86 for 9600; =0x85 for 19200; =0x84 for 38400 baudrates at crystal frequency of 11.0592 MHz 
T3FD=0x08;

EA = 1;					// Enable Interrupts
ES=1;

	for(;;)	
	{

	}
}