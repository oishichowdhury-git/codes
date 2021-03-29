#include<stdio.h>
void main()
{
    printf("\t\t The temperature conversion headding\n");
    float fahr, celsius;
    float lower, upper, step;
    lower = -20; /* lower limit of temperatuire scale */
    upper = 100; /* upper limit */
    step = 10; /* step size */
    celsius = lower;
    while (celsius<= upper) {
    fahr = (9.0*celsius/5.0) + 32.0;
    printf("%3.0f %6.1f\n", celsius, fahr);
    celsius = celsius + step;
 }
}