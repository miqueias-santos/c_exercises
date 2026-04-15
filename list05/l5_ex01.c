#include <stdio.h>
#include <stdlib.h>
#define STEP 5
void print(int *v, int size);

int main(){
    // Variable of allocation
    int *v = NULL;
    int capacity = 0;
    int size = 0;

    int input;
    int *aux;

    scanf("%d", &input);
    while (input != EOF) {
        if (size >= capacity) {
            capacity += STEP;
            aux = realloc(v, capacity * sizeof(int));
        }   v = aux;
        
        v[size++] = input;
        
        scanf("%d", &input);
    }

    print(v, size);

    free(v);
    return 0;
}
void print(int *v, int size)
{
    printf("Mais um bom dia de trabalho!\n");
    for (int i = 0; i < size; i++) {
        if (v[i] & 1) printf("%d\n", v[i]);
    }
    for (int i = 0; i < size; i++) {
        if (~v[i] & 1) printf("%d\n", v[i]);
    }
    printf("Vou visitar esses lugares de novo... algum dia.");

}