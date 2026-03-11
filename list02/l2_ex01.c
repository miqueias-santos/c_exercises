#include <stdio.h>

int main(void){
    int N, K, P;
    //Ache o um número maior igual a N e menor que K, com P fatores primos distintos
    scanf("%d %d %d", &N, &K, &P);

    
    for (int i = N; i < K; i++){ //para cada número de N a K 
        int current = N; //analisando-o
        int n_primos_distintos;
        
        for (int div = 3; div < current/3; div++){ //checando a divisibilidade por primos distintos de 2
            if(current%div == 0){ //divisivel por div. Descobrindo se div é primo
                int is_primo = 1;
                
                for(int k = 2; is_primo && k < div/2; k++){
                    if(div%k == 0)
                }

            }
        } 
    }


    return 0;
}