#include <stdio.h>
#include <string.h>

int main(void){
    int numero_clientes, X, Y;
    scanf("%d %d %d", &numero_clientes, &X, &Y);

    int hora[Y], minuto[Y], quant[Y];
    for (int i = 0; i < Y; i++){
        scanf("%d:%d %d", &hora[i], &minuto[i], &quant[i]);
    }

    int n_lata = 0;
    int n_cliente = 0;
    int lata_per_cliente = 0;
    while(n_lata <= 50 && n_cliente <= numero_clientes){
        lata_per_cliente = n_lata;
        if (X != 0)
        {
            if((n_cliente+1)%X == 0){
                n_lata++;
            }
        }
        int minuto_c = n_cliente * 3;
        int hora_c = minuto_c/60 + 7;
        minuto_c %= 60;
        
        for(int i = 0; i < Y; i++){
            if(hora_c == hora[i] && minuto_c == minuto[i]){
                
                if(X != 0){
                    if((n_cliente+1)%X == 0){
                        n_lata += (quant[i] - 1);
                    }
                    else{
                        n_lata += quant[i];
                    }
                }
                else{
                    n_lata += quant[i];
                }
            }
        }
    lata_per_cliente = n_lata - lata_per_cliente;
    n_cliente++;

    }
    if(n_lata < 50){
        printf("Ainda nao foram vendidas latas suficientes. Faltam %d latas.", 50 - n_lata);
    }
    else{
        int minuto_c = (n_cliente-1) * 3;
        int hora_c = minuto_c/60 + 7;
        minuto_c %= 60;
        if(minuto_c < 10){
            if(lata_per_cliente == 1){
                printf("Quem levou a cesta basica foi o %d* cliente atendido por coragem, as 0%d:0%d. Que comprou %d lata.", n_cliente-1, hora_c, minuto_c, lata_per_cliente);
            }
            else{
                printf("Quem levou a cesta basica foi o %d* cliente atendido por coragem, as 0%d:0%d. Que comprou %d latas.", n_cliente-1, hora_c, minuto_c, lata_per_cliente);
            }
        } 
        else{
            if(lata_per_cliente == 1){
                printf("Quem levou a cesta basica foi o %d* cliente atendido por coragem, as 0%d:%d. Que comprou %d lata.", n_cliente-1, hora_c, minuto_c, lata_per_cliente);
            }
            else{
                printf("Quem levou a cesta basica foi o %d* cliente atendido por coragem, as 0%d:%d. Que comprou %d latas.", n_cliente-1, hora_c, minuto_c, lata_per_cliente);
            }

        }
        

    }


    return 0;
}