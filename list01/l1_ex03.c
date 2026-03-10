#include <stdio.h>
#include <stdlib.h>

//a coordenada de destino é (1, 1)

/* Considerações: primeiro quadrante x > 0, y > 0;
                  segundo quadrante x < 0, y > 0;
                  terceiro quadrante x < 0, y < 0;
                  quarto quadrante x > 0, y < 0;     
*/ 
int main(void){
    int x, y, quad_evitado, quad_destino;
    int Dx;
    int Dy;
    
    scanf("%d %d %d", &x, &y, &quad_evitado);

    //detectar quadrante
    if(x > 0 && x > 0) {
        Dx = -1 - x;
        Dy = -1 - y;
        quad_destino = 3;
        printf("Estou no 1, vou pro 3");
    }
    else if(x < 0 && y > 0) {
        Dx = 1 - x;
        Dy = -1 - y;
        quad_destino = 4;
        printf("Estou no 2, vou pro 4");
    }
    else if(x < 0 && y < 0) {
        Dx = 1 - x;
        Dy = 1 - y;
        quad_destino = 1;
        printf("Estou no 3, vou pro 1");
    }
    else if(x > 0 && y < 0) {
        Dx = -1 - x;
        Dy = 1 - y;
        quad_destino = 2;
        printf("Estou no 4, vou pro 2");
    }

    if(quad_evitado == quad_destino || abs(quad_evitado - quad_destino) == 2) printf("caminhada invalida\n");
    else{
        //tome x
        x += Dx;
        if(x > 0 && y > 0 && quad_evitado == 1){
            printf("%d passos em y e %d passos em x", abs(Dy), abs(Dx));
        }
        else if(x < 0 && y > 0 && quad_evitado == 2){
            printf("%d passos em y e %d passos em x", abs(Dy), abs(Dx));
        }
        else if(x < 0 && y < 0 && quad_evitado == 3){
            printf("%d passos em y e %d passos em x", abs(Dy), abs(Dx));
        }
        else if(x > 0 && y < 0 && quad_evitado == 4){
            printf("%d passos em y e %d passos em x", abs(Dy), abs(Dx));
        }
        else{
            printf("%d passos em x e %d passos em y", abs(Dx), abs(Dy));
        }
    }
    return 0;
}