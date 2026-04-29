#include <stdio.h>
#include <stdlib.h>

int calibrar(int a);
int saturar(int a);
int amplificar(int a);
void pipeline(int **matrix, int row, int col, int k, int *fi);
void modificar(int **matrix, int row, int col);
int **safe_alloc(int row, int col);
void safe_free(int **matrix, int row);
void recieve(int **matrix, const int row, const int col);
int print_and_select(int **matrix, const int row, const int col, int *x, int *y);
int main()
{
    int row, col;
    int maior_elemento;
    int x, y;
    scanf("%d %d", &row, &col);
    int **matrix = safe_alloc(row, col);
    recieve(matrix, row, col);

    modificar(matrix, row, col);
    maior_elemento = print_and_select(matrix, row, col, &x, &y);

    printf("Sensor critico: %d\n", maior_elemento);
    printf("Posicao: (%d,%d)", x, y);
    safe_free(matrix, row);
}

int **safe_alloc(int row, int col) 
{
    int** matrix = NULL;
    matrix = malloc(row * sizeof(int *));
    if(matrix == NULL) return NULL;
    
    for (int i = 0; i < row; i++) {
        matrix[i] = malloc(col * sizeof(int));
        if (matrix[i] == NULL) {
            for (int j = i - 1; j >= 0; j--) free(matrix[j]);
        }
    }
    return matrix;
}

void safe_free(int **matrix, int row) 
{
    for (int i = 0; i < row; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

void recieve(int **matrix, const int row, const int col)
{
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            scanf("%d", matrix[i] + j);
        }
    }
}

int print_and_select(int **matrix, const int row, const int col, int *x, int *y)
{
    printf("Matriz processada:\n");
    int maior;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (i == 0 && j == 0) {
                maior = matrix[i][j];
                *x = 0; *y = 0;
            }
            else if (maior < matrix[i][j]) {
                maior = matrix[i][j];
                *x = i;
                *y = j;
            }
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    return maior;
}

int calibrar(int a) 
{
    return a + 5;
}

int saturar(int a) 
{
    int retorno = (a > 80) ? 80 : a;
    return retorno;
}

int amplificar(int a) 
{
    return 2 * a;
}

void pipeline(int **matrix, int row, int col, int k, int *fi)
{
    int (*f)(int) = NULL;
    for (int i = 0; i < k; i++) {
        switch (fi[i])
        {
        case 1:
            f = calibrar;
            break;
        
        case 2:
            f = saturar;
            break;
        case 3:
            f = amplificar;
            break;
        }
    
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                matrix[i][j] = f(matrix[i][j]);
            }
        }
    }
}

void modificar(int **matrix, int row, int col)
{
    int num = -1;
    int *fi = NULL;
    int *aux;
    int k;

    scanf("%d", &num);
    while (num != 0) { // Recebe uma sequência, apontada por fi, de operações
        k = 1;
        if (num == 4) scanf("%d", &k); 
        aux = realloc(fi, k * sizeof(int));
        if (aux == NULL) {
            printf("Allocation has failed");
            free(fi);
            exit(1);
        }
        fi = aux;
        if (k == 1) fi[0] = num;
        else {
            for (int i = 0; i < k; i++) scanf("%d", fi + i); 
        }
        pipeline(matrix, row, col, k, fi);
    
        scanf("%d", &num); 
    }

    free(fi);
}