#include <stdio.h>
int main() 
{
    int a = 5;
    int *p = &a; //p é uma variável, logo tem endereço e valor
    int *p1 = p + 1; 

    printf("a: %d\n", a);
    printf("&a == p: %p\n", p);
    printf("&p: %p\n", &p); // &(&p) / &(p + 1) expression must be an lvalue or a function designator
    printf("*(p + 1): %d\n", &(p + 1));
    printf("p + 1: %p\n", p + 1);
    printf("&(p + 1): %p\n", p1);

}
/*
    Categorias de valores:


*/