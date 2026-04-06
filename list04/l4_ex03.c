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
int analise(int grid[][MAX_COL], int m, int n, int o[], int i[]){
    char dirs[MAX_ROW];
    int passos = 0;
    int p[2] = {o[0], o[1]};

}