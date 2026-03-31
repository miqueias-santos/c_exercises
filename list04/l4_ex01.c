#include <stdio.h>
#define MAX_ROW 100
#define MAX_COL 101

void read_matrix(char matrix[][MAX_COL], int m);
void print_matrix(char matrix[][MAX_COL], int m, int n);
void set_matrix(char matrix[][MAX_COL], int m, int n);

int main(void){
    char grid[MAX_ROW][MAX_COL];
    int m, 
        n;
    scanf("%d %d", &m, &n);
    read_matrix(grid, m);
    set_matrix(grid, m, n);
    print_matrix(grid, m, n);
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
    // percorrendo a matriz por colunas
    int stop;
    for(int j = 0; j < n; j++){
        for(int i = 0; i < m; i++){// obs: index
            stop = 0;
            if(matrix[i][j] == 'o' && i < m - 1){ // sendo 'o' e não estando na última linha 
                
                for(int k = i + 1; k < m && !stop; k++){ // estenda 'o' até encontrar #
                    if(matrix[k][j] != '#' && matrix[k][j] != 'o') matrix[k][j] = 'o'; 
                    else stop = 1;
                }
                
                if(matrix[i + 1][j] == '#'){ // verifique se há # ou 'o' embaixo do 'o' em questão
                    stop = 1;
                    for(int k = 0; k < n; k++){ // se há # embaixo do 'o', essa linha tem '#' (uma ou mais, e deve ser analisada)
                        if(matrix[i + 1][k] == '#')  matrix[i][k] = 'o';
                        if(k < n - 1){
                            if(matrix[i + 1][k] != '#' && matrix[i + 1][k + 1] == '#') matrix[i][k] = 'o';
                        }
                        if(k > 0){
                            if(matrix[i  + 1][k] != '#' && matrix[i + 1][k - 1] == '#') matrix[i][k] = 'o';
                        }
                    }
                    i = 0, j = 0;
                    

                }
                
                
            }
        }       
    }
}
