#include <stdlib.h>
#include <stdio.h>
struct pessoa {
    char* nome;
    int idade;

    struct filho { char* nome; int idade; } j; // definindo um tip
    struct filho h;
};

int main() {
    struct pessoa Eu; // ?
    Eu.j.nome;
    struct pessoa *p = &Eu; // Tipo 'struct pessoa'
   // printf("%p\n", main);
    printf("%p\n", p);
    printf("%p\n", p + 1);
}