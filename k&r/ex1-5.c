#include <stdio.h>

/* print Fahrenheit-Celsius table
   for fahr = 300, 280, ..., 0; floating-point version */

int main()
{   
    int fahr;
    printf("TEMPERATURE CONVERSOR °F TO °C, IN RANGE %.0f TO %.0f, STEP OF %.0f\n" "FAHRENHEIT  CELSIUS\n", 300, 0, -20); // header
    for (fahr = 300; fahr >= 0; fahr = fahr - 20) 
        printf("%5d %11.1f\n", fahr, (5.0/9.0) * (fahr-32.0));
}
