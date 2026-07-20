#include <stdio.h>

/* print Celsius-Fahrenheit table 
   for celsius = -17.8, -6.7, ...; from -17.8 to 148.9 °C, step = 11.1 */

int main() {
    float lower, upper, step;
    float celsius, fahr;

    lower = -178e-1;
    upper = 1489e-1;
    step = 111e-1;

    while (lower <= upper) {
        celsius = lower;
        fahr = (9.0/5.0)*celsius + 32;
        lower += step;
        printf("%.1f %.1f\n", celsius, fahr);
    }

}