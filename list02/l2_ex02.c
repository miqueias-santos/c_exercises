#include <stdio.h>
# include <stdlib.h>

int main(void){
    int x;
    int n_canais;
    scanf("%d %d", &x, &n_canais);

    int melhor_canal;
    int minuto;
    int is_vip;
    int anterior, atual; //termos da sequ�ncia

    //vari�veis de an�lises e loop
    int dif_ant = 2000000; //um n�mero alto qualquer
    int dif;
    int temp;
    int cond;
    int w;
    for(int c = 1; c <= n_canais; c++){ //para cada canal
       scanf("%d %d", &anterior, &atual);
        
        cond = 1;
        w = 1;
        while (cond){
            if (w == 1) {
                dif = abs(x - anterior);
                w++;
            }
            else if (w == 2){
                if (dif > abs(x - atual)){
                    dif = abs(x - atual);
                    w++;
                }
                else if(dif == abs(x - atual)){
                    w++;
                }
                else {
                    w--; cond = 0;
                    anterior = atual;

                }

            }
            else{
                temp = atual;
                atual = atual + anterior;
                anterior = temp;
        
                if (dif <= abs(x - atual)){
                    w--; cond = 0; 
                }
                else{
                    dif = abs(x - atual);
                    w++;
                }

            }
        }

        if (dif <= dif_ant){
            melhor_canal = c;
            minuto = w;
            is_vip = ((anterior/10) + (anterior%10)) > 10 ? 1 : 0;
            dif_ant = dif;
        }

    }
    if(is_vip) printf("Xupenio, para ir ao lulupalooza vc deve entrar no canal %d e sera chamado mais ou menos no minuto %d e com o VIP garantido!!!", melhor_canal, minuto);
    else printf("Xupenio, para ir ao lulupalooza vc deve entrar no canal %d e sera chamado mais ou menos no minuto %d, mas o ingresso VIP n�o vai rolar :(", melhor_canal, minuto);


    return 0;
}