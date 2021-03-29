#include<stdio.h>
float temp_conv(float fahr)
{
    return ((5.0/9.0) * (fahr-32.0));
}
void main()
{
    printf("\t\t The temperature conversion headding\n");
    float fahr, celsius;
    float lower, upper, step;
    lower = 0; /* lower limit of temperatuire scale */
    upper = 300; /* upper limit */
    step = 20; /* step size */
    fahr = lower;
    while (fahr <= upper) {
    celsius = temp_conv(fahr);
    printf("%3.0f %6.1f\n", fahr, celsius);
    fahr = fahr + step;
 }
}