#include<ADUC841.h>
#include <absacc.h>		// to access DBYTE
#include<stdio.h>	   // for display string
#include<intrins.h>

sbit LED=P3^4;
int delay=100; 
void MiliDelay(unsigned int);	   // Function definition
void interpreting_cmd();
void MiliDelay(unsigned int itime)		 // 1 mili second DELAY FUNCTION 
{
unsigned int a,b;
for(a=0;a<itime;a++)
{
for (b=0;b<1182;b++) ;
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
			delay=100;
			break;

			case '2':
			delay=200;
			break;

			case '3':
			delay=300;
			break;

			case '4':
			delay=400;
			break;

			case '5':
			delay=500;
			break;

			case '6':
			delay=600;
			break;

			case '7':
			delay=700;
			break;

			case '8':
			delay=800;
			break;

			case '9':
			delay=900;
			break;

			case '0':
			delay=1000;
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

for(;;)					// Loop Forever
{
LED = LED ^ 1;							  // Complement P3.4	P3 ^= 0x10 => P3 = P3 ^ 0x10    ^ is ex or operation  
                        	
MiliDelay(delay);                          // Call delay routine

}
}