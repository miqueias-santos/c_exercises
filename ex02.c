#include <stdio.h>
#include <math.h>

typedef struct{

  double x;
  double y;

} Ponto;
 
int main() {
 
    Ponto p1, p2;
    scanf("%lf %lf", &p1.x, &p1.y);
    scanf("%lf %lf", &p2.x, &p2.y);
    
    double D = sqrt((p2.x - p1.x) * (p2.x - p1.x) + (p2.y - p1.y) *(p2.y - p1.y));
    
    printf("%.4lf\n", D);
    return 0;
}
