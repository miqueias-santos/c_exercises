#include <stdio.h>
#define PI 3.14159

int main() {
    
    double r = 0;
    //Lê um um valor flutuante para o raio
    scanf("%lf", &r);
    
    double A = r * r * PI;
    printf("A=%.4lf\n", A);
 
    return 0;
}
