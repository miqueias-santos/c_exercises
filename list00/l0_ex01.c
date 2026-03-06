#include <stdio.h>
#define PI 3.14159

int main() {
 
   double R = 0.0;
   scanf("%lf", &R);
   
   double VOLUME = (4.0/3) * (R * R * R) * PI; 
   
   printf("VOLUME = %.3lf\n", VOLUME);
   
    return 0;
}
