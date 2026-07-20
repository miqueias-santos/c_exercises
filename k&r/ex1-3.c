#include <stdio.h>

/* print Fahrenheit-Celsius table
   for fahr = 0, 20, ..., 300; floating-point version */

int main()
{
    float fahr, celsius;
    float lower, upper, step;
    
    lower = 0; /* lower limit of temperatuire scale */
    upper = 300; /* upper limit */
    step = 20; /* step size */
    
    fahr = lower;
    printf("TEMPERATURE CONVERSOR °F TO °C, IN RANGE %.0f TO %.0f, STEP OF %.0f\n" "FAHRENHEIT  CELSIUS\n", lower, upper, step); // header
    while (fahr <= upper) {
        celsius = (5.0/9.0) * (fahr-32.0);
        printf("%5.0f %11.1f\n", fahr, celsius);
        fahr = fahr + step;
    }
}
