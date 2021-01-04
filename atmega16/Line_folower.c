//Line folower
//follows the black line

#include<avr/io.h>
void main()
{
DDRA = 0x00;
// Set PORTA as input port
DDRB = 0xFF;
// Set PORTB as output port
PORTA = 0xFF;
// Set the default voltage of Port A HIGH (Pull-up)
char c;
while(1)
// Infinite loop
{
c = PINA;
if(c == 0b11111100)
// Both the sensor are obstacle free.
PORTB =0b00000000;
//Stop
if(c == 0b11111110)
// If only Left Sensor detects an obstacle
PORTB = 0b00000010;
//Turn Left: Left stop, Right forward
if(c == 0b11111101)
// If only Right sensor detects obstacle
PORTB= 0b00001000;
//Turn Right: Left forward, Right stop
if(c == 0b11111111)
// If both of them detects obstacle
PORTB= 0b00001010;
//Move forward
}
}