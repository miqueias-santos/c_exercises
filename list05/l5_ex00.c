/* Sistema de Notas da Escola CInal do Saber */
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
float mean(float *notes, int number_notes);
float bigger(float *notes, int number_notes, int *position);
float smaller(float *notes, int number_notes, int *position);
int above_mean(float *notes, int number_notes);
float *bubble_sort(float *vector, int size);
float median(float *notes, int number_notes);
int count(float* vector, int size, float element);
float mode(float *notes, int number_notes);
void report(float *notes, int number_notes);

int main()
{
    int n, k;
    float *notes, *aux;
    
    scanf("%d", &n);
    
    notes = malloc(n * sizeof(float));
    if (notes == NULL) {
        printf("Allocation have failed");
        return 1;
    }
    for (int i = 0; i < n; i++) {
        scanf("%f", notes + i);
    }

    printf("Relatorio inicial\n");
    report(notes, n);
    
    scanf("%d", &k);
    if(k != 0) {
        aux = realloc(notes, (n + k) * sizeof(float));
        if (aux == NULL) {
            printf("Reallocation have failed");
            free(notes);
            return 1;
        }
        notes = aux;
    }
    for (int i = 0; i < k; i++) {
        scanf("%f", notes + n + i);
    }

    printf("\nRelatorio atualizado\n");
    report(notes, n + k);

    free(notes);
    return 0;
}

float mean(float *notes, int number_notes)
{
    float sum = 0;
    for (int i = 0; i < number_notes; i++) {
        sum += notes[i]; 
    }
    return sum/(float)number_notes;
}

float bigger(float *notes, int number_notes, int *position) 
{
    float bigger; 
    int order;

    bigger = INT_MIN;
    order = -1; // Invalid position
    
    for (int i = 0; i < number_notes; i++) {
        if (notes[i] > bigger) {
            bigger = notes[i];
            order = i + 1;
        }
    }
    // Double return
    *position = order;
    return bigger;
}

float smaller(float *notes, int number_notes, int *position) 
{
    float smaller;
    int order;

    smaller = INT_MAX;
    order = -1; // Invalid position

    for (int i = 0; i < number_notes; i++) {
        if (notes[i] < smaller) {
            smaller = notes[i];
            order = i + 1;
        }
    }
    // Double return
    *position = order; /* Consequência do uso de ponteiros para alterar valores fora do escopo da função */
    return smaller;
}

int above_mean(float *notes, int number_notes) 
{
    float media = mean(notes, number_notes);
    int count = 0;
    for (int i = 0; i < number_notes; i++) {
        if (notes[i] > media) count++;
    }
    return count;
}

float *bubble_sort(float *vector, int size) 
{
    float *ordenation = malloc(size * sizeof(float));
    int isnt_orderded = 1;
    float aux;

    if (ordenation == NULL) {
        printf("Allocation have failed");
        return NULL;
    }

    for (int i = 0; i < size; i++) {
        ordenation[i] = vector[i];
    }

    while (isnt_orderded) {
        isnt_orderded = 0;
        for (int i = 0; i < size - 1; i++) {
            if (ordenation[i] > ordenation[i + 1]) {
                aux = ordenation[i];
                ordenation[i] = ordenation[i + 1];
                ordenation[i + 1] = aux;
                isnt_orderded = 1;
            }
        }
    }
    return ordenation;
}

float median(float *notes, int number_notes)
{
    float median;
    float *vector = bubble_sort(notes, number_notes);
    if (vector == NULL) {
        printf("Error");
        return -1;
    }

    if (number_notes & 1) { // Odd
        median = vector[number_notes / 2];
    }
    else { // Even
        median = (vector[number_notes / 2] + vector[number_notes / 2 - 1]) / 2.0f;
    }
    
    free(vector);
    
    return median;
}

int count(float* vector, int size, float element)
{
    int counter = 0;
    for (int i = 0; i < size; i++) {
        if(vector[i] == element) counter++;
    }

    return counter;
}

float mode(float *notes, int number_notes)
{
    float element;
    int recorrency = 0;
    int count = 0;
    int no_mode;

    for (int i = 0; i < number_notes; i++) {
        count = 0;
        for (int j = 0; j < number_notes; j++) {
            if (notes[i] == notes[j]) count++;
        }
        if (recorrency < count) {
            recorrency = count;
            element = notes[i];
            no_mode = 0;
        }
        else if(recorrency == count && notes[i] != element) {
            no_mode = 1;
        }
    }
    if (no_mode) element = -1;
    return element;
}

void report(float *notes, int number_notes)
{
    float media, maior, menor, mediana, moda;
    int acima_da_media, pos_maior, pos_menor;

    media = mean(notes, number_notes);
    maior = bigger(notes, number_notes, &pos_maior);
    menor = smaller(notes, number_notes, &pos_menor);
    acima_da_media = above_mean(notes, number_notes);
    mediana = median(notes, number_notes);
    moda = mode(notes, number_notes);

    printf("Media: %.2f\n", media);
    printf("Maior nota: %.2f (aluno %d)\n", maior, pos_maior);
    printf("Menor nota: %.2f (aluno %d)\n", menor, pos_menor);
    printf("Acima da media: %d\n", acima_da_media);
    printf("Mediana: %.2f\n", mediana);
    
    if(moda == -1.0f) printf("Moda: Nao ha moda unica\n");
    else printf("Moda: %.2f\n", moda);
}
