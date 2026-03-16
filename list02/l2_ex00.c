#include <stdio.h>
#include <stdlib.h>
int main(void){
    unsigned char c;
    scanf(" %c", &c);
    int idx_max_row = c % 64;
    int idx_max_col = 2 * idx_max_row - 1;
    char TELA;
    for(int i = 1; i <= idx_max_row; i++){ //index de linha. [1, idx_max_row]
        int n_points = idx_max_col - (2 * i - 1); 
        for(int j = 1; j <= idx_max_col; j++){
            if(j <= n_points/2) printf("%c", '.');
            else if((j - n_points/2) <= 2*i - 1){
                int idx_letra = j - n_points/2;
                printf("%c", -abs(idx_letra - i) + i + 64);
            }
            else printf("%c", '.');
        }
        printf("\n");
    }
    return 0;
}