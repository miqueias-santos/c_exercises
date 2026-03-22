#include <stdio.h>
int main(void){

    int T;
    scanf("%d", &T);

    for (int j = 0; j < T; j++){
        int N;
        
        scanf("%d", &N);
        int array[N];

        for (int i = 0; i < N; i++) scanf("%d", &array[i]);

        int len_seq = 1; //Tamanho da sequência de decrescentes em questão
        int len_aux = 1; //Tamanho da maior sequência de decrescentes
        int end_seq = 0; //Index do começo da maior sequência de decrescentes

        for (int i = 0; i <= N - 2; i++){
            if (array[i+1] < array[i]){ // do [0] < [1] ao [n-2] < [n-1]
                len_seq++;
                
                if (i == N - 2 && len_seq > len_aux){
                    len_aux = len_seq;
                    end_seq = i + 1 - len_seq + 1;
                }

            }
            else{
                if (len_seq > len_aux){
                    len_aux = len_seq;
                    end_seq = i+1 - len_seq;
                }
                len_seq = 1;

            }
        }

    //printar
        len_aux = (len_aux == 1) ? 0 : len_aux;
        printf("%d\n", len_aux);
        for(int i = end_seq; i - end_seq < len_aux ; i++){
            if(i - end_seq == len_aux - 1) printf("%d", array[i]);
            else rintf("%d", array[i]);
            
        }
        if(j != T - 1) printf("\n");
    }
    return 0;
}