#include <stdio.h>
#include <stdlib.h>

int **safe_alloc(const int row, const int col);
void safe_free(int **matrix, const int row);
void write(int **matrix, const int row, const int col);
void read(const int **matrix, const int row, const int col); //ver: const int * const *matrix
int sqr(int a);
int dob(int a);
int abs(int a);
void apply(int **matrix, const int row, const int col, int (*atk)(int));

int main()
{
    int **matrix;
    int row, col;
    int (*attack)(int) = NULL;
    int op;
    
    scanf("%d %d", &row, &col);
    matrix = safe_alloc(row, col);
    if (matrix == NULL) {
        printf("Allocation has failed.");
        return 1;
    }
    write(matrix, row, col);
    scanf("%d", &op);
    
    switch (op) {
        case 1: 
            attack = dob;
            break;
        case 2:
            attack = sqr;
            break;
        case 3:
            attack = abs;
            break;
    }
    if (attack != NULL) {
        apply(matrix, row, col, attack);
        read(matrix, row, col);
    }
    else printf("Error!\n");
    
    safe_free(matrix, row);
    return 0;
}

int **safe_alloc(const int row, const int col)
{
    int **matrix = NULL;
    
    matrix = malloc(row * sizeof(int *));
    if (matrix == NULL) return NULL;

    for (int i = 0; i < row; i++) {
        matrix[i] = malloc(col * sizeof(int));

        if (matrix[i] == NULL) {
            for (int j = i - 1; j >= 0; j--) free(matrix[j]);
            free(matrix);
            return NULL;
        }
    }

    return matrix;
}

void safe_free(int **matrix, const int row)
{
    for (int i = 0; i < row; i++) free(matrix[i]);
    free(matrix);
}

void write(int **matrix, const int row, const int col)
{
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            scanf("%d", matrix[i] + j);
        }
    }
}

void read(const int **matrix, const int row, const int col)
{
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int sqr(int a)
{
    return a * a;
}

int dob(int a)
{
    return 2 * a;
}

int abs(int a)
{
    a = a > 0 ? a : -a;
    return a;
}

void apply(int **matrix, const int row, const int col, int (*atk)(int)) 
{
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            matrix[i][j] = atk(matrix[i][j]);
        }
    }
}
