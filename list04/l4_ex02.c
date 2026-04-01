#include <stdio.h>
void add_one(int matrix[][4], int i, int j);
void analise(int matrix[][4]);

int main(void){
    int map[4][4] = {{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
    char dir;
    int j = 0, i = 0;
    for(int k = 0; k < 20; k++){
        scanf(" %c", &dir);
        if(dir == 'b') i++;
        else if(dir == 'c') i--;
        else if(dir == 'e') j--;
        else j++;
        add_one(map, i, j);

    }
    analise(map);

    return 0;
}

void add_one(int matrix[][4], int i, int j){
    matrix[i][j]++;
}

void analise(int matrix[][4]){
    int element = 0;
    int element_i = 0, element_j = 0;
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            if(matrix[i][j] > element) {
                element = matrix[i][j];
                element_i = i;
                element_j = j;
            }
        }
    }
    printf("Coordenada X:%d, Y:%d", element_j, element_i);
}
