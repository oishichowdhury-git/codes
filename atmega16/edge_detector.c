//Edge detector
// Moves within the boundary

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
PORTB =0b00000110;
//Turn Hard Left: Left Back, Right Forward, it's an edge ahead
if(c == 0b11111110)
// If only Left Sensor detects an obstacle, edge at right
PORTB = 0b00000010;
//Turn Left: Left Stop, Right Forward
if(c == 0b11111101)
// If only Right sensor detects obstacle, edge at left
PORTB= 0b00001000;
//Turn Right: Left Forward, Right Stop
if(c == 0b11111111)
// If both of them detects obstacle, no edge
PORTB= 0b00001010;
//Move Forward
}
}