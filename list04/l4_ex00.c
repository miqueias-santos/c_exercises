#include <stdio.h>
#define MAX_ROW 100
#define MAX_COL 101

int main(void){
    char matrix[MAX_ROW][MAX_COL];
    int m, 
        n;
    scanf("%d %d", &m, &n);

    for(int i = 0; i < m; i++){
        scanf(" %100[^\n]", matrix[i]);
    }

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
                        matrix[i][j + 1] = 'P';
                    }
                }

                //pondo *. Só será posto se o espaço for vazio, isto é, nem P, nem +
                if()
                if()
                if()
                if()

            }

        }
    }

    return 0;
}
void set_matrix(char matrix[][], )