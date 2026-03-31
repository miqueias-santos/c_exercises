#include <stdio.h>
#define MAX_ROW 100
#define MAX_COL 101
void read_matrix(char matrix[][MAX_COL], int m);
void print_matrix(char matrix[][MAX_COL], int m, int n);
void set_matrix(char matrix[][MAX_COL], int m, int n);

int main(void){
    char matrix[MAX_ROW][MAX_COL];
    int m, 
        n;
    scanf("%d %d", &m, &n);

/* Recebendo a matriz */
    read_matrix(matrix, n);

/* Tratando a matriz */
    set_matrix(matrix, m, n);
    print_matrix(matrix, m, n);


    return 0;
}


void read_matrix(char matrix[][MAX_COL], int m){
    for(int i = 0; i < m; i++){
        scanf(" %100[^\n]", matrix[i]);
    }
}

void print_matrix(char matrix[][MAX_COL], int m, int n){
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            printf("%c", matrix[i][j]);
        }
        printf("\n");
    }
}

void set_matrix(char matrix[][MAX_COL], int m, int n){
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(matrix[i][j] == 'P'){
                //pondo +. Apenas não será posto se P estiver adjacente ou não houver espaço
                if(i > 0){ //se faz sentido por em cima
                    if(matrix[i - 1][j] != 'P'){
                        matrix[i - 1][j] = '+';
                    }
                }
                if(i < m - 1){//se faz sentido por embaixo
                    if(matrix[i + 1][j] != 'P'){
                        matrix[i + 1][j] = '+';
                    }
                }
                if(j > 0){ //se faz sentido por a esquerda
                    if(matrix[i][j - 1] != 'P'){
                        matrix[i][j - 1] = '+';
                    }
                }
                if(j < n - 1){ //se faz sentido por a direita
                    if(matrix[i][j + 1] != 'P'){
                        matrix[i][j + 1] = '+';
                    }
                }

                //pondo *. Só será posto se o espaço for vazio, isto é, nem P, nem +
                if(i > 0 && j > 0){ //se faz sentido por no canto superior esquerdo
                    if(matrix[i - 1][j - 1] == '-'){
                        matrix[i - 1][j - 1] = 'x';
                    }
                }
                if(i > 0 && j < n - 1){ //se faz sentido por no canto superior direito
                    if(matrix[i - 1][j + 1] == '-'){
                        matrix[i - 1][j + 1] = 'x';
                    }
                }
                if(i < m - 1 && j < n - 1){ //se faz sentido por no canto inferior direito
                    if(matrix[i + 1][j + 1] == '-'){
                        matrix[i + 1][j + 1] = 'x';
                    }
                }
                if(i < m - 1 && j > 0){ //se faz sentido por no canto inferior esquerdo
                    if(matrix[i + 1][j - 1] == '-'){
                        matrix[i + 1][j - 1] = 'x';
                    }
                }
            }
        }
    }

}
