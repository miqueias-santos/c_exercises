#include <stdio.h>

int main(void){
    int N, K, P, R = -1, Q = 0; //
    //R é o menor número maior igual a N e menor que K, com P fatores primos distintos. Q é a quantidade de números com a propriedade de R, exceto R
    scanf("%d %d %d", &N, &K, &P);
    int current;
    int valid;
    int n_primos_distintos;
    int lim;
    for (int i = N; i < K; i++){ //para cada número partindo de N a K 
        current = i; //analisando-o
        valid = 1;
        n_primos_distintos = 0; //impares
        lim = 1; //variável para performance. Diminui o número de vezes que o for roda
        
        for (int div = 3; valid && div <= current/lim; div++){ //checando a divisibilidade por primos distintos de 2
            
            if(current % div == 0){ //divisivel por div. Descobrindo se div é primo
                int is_primo = 1;
                if(div % 2 == 0) is_primo = 0;
                if(div % 2 == 1) for(int k = 3; is_primo && k <= div/k; k += 2) if(div % k == 0) is_primo = 0;

                if(is_primo){ //é primo, agora vemos o fator não se repete.

                    if( ((current/div) % div) != 0){ //não se repete para 1 divisor primo
                        lim *= div;
                        n_primos_distintos++;
                    }
                    else valid = 0; //se repete, o número não é mais válido
                }
            }

        } 

        if(valid){
            if(n_primos_distintos == P) {
                if(R == -1) R = current;
                Q++;
            }

        }

        
    }
    if(R == -1) printf("Poxa dudinha, me desculpa, nao achei os numeros mas vou te mandar uma foto de um gatinho fofo.\n");
    else printf("%d %d\n", R, Q-1);

    return 0;
}