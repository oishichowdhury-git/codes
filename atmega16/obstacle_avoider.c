// Obstacle avoider

// Keeps moving, avoids obstacles

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
PORTB =0b00001010;
//Move Forward
if(c == 0b11111110)
// If Left Sensor detects an obstacle
PORTB = 0b00001000;
//Turn Right: Left Forward, Right Stop
if(c == 0b11111101)
// If Right sensor detects obstacle
PORTB= 0b00000010;
//Turn Left: Left Stop, Right Forward
if(c == 0b11111111)
// If both of them detects obstacle
PORTB= 0b00000110;
//Turn Hard Left: Left Back, Right Forward
}
}