#include <stdio.h>
#define MAX_COL 101
#define MAX_ROW 100

int main()
{
    char grid[MAX_ROW][MAX_COL];
    int m, n;
    int o[2];
    int d[2];
    
    
    
    
    scanf("%dx%d", &m, &n);

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf(" %c", &grid[i][j]);
            if (grid[i][j] == 'o') {
                o[0] = i;
                o[1] = j;
            }
            else if (grid[i][j] == 'd') {
                d[0] = i;
                d[1] = j;
            }
        }
    }
    






    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%c", grid[i][j]);
        }
        printf("\n");
    }
    
   

}
int analise(char grid[][MAX_COL], int m, int n, int o[], int d[]){
    char dirs[MAX_ROW];
    int passos = 0;
    int rebeka[2] = {o[0], o[1]};
    int direcao_prior[2];
    direcao_prior[1] = (d[1] - o[1] > 0) ? 1 : -1;
    direcao_prior[0] = (d[0] - o[0] < 0) ? -1 : 1; //{i, j}
    while (out) {
//checar os caminhos disponíveis
        if


    }



    int imp = 0;
    for (int i = 0; i < 4; i++) {
        
        
        
        switch (i)
        {
        case 1:
            
            break;
        
        default:
            break;
        }
    }

}
int decisão(char grid[][MAX_COL], int m, int n, int rebeka[], int direcao_prior[], int max_passos)
{
    
    if(grid[rebeka[0]][rebeka[1]] == '#') return -1;
    int aval[2];
    for (int k = 0; k < 4; k++) { //i, j, -i, -j
        if (k = 0){
            aval[0] = rebeka[0] + direcao_prior[0];
            if (aval[0] > 0 && aval[0] < m - 1) {
                passos = decisão(grid, m, n, aval, direcao_prior);
            }
        }
        else if (k = 1){
            aval[1] = rebeka[1] + direcao_prior[1];
            if (aval[1] > 0 && aval[1] < n - 1) {
                
            }
        }
        else if (k = 2){
            aval[0] = rebeka[0] - direcao_prior[0];
            if (aval[0] > 0 && aval[0] < m - 1) {
                
            }
        }
        else {
            aval[1] = rebeka[1] - direcao_prior[1];
            if (aval[1] > 0 && aval[1] < n - 1) {
                
            }
        }
        if (passos != -1 && passos > max_passos) max_passos = passos;

        
        

    }

}