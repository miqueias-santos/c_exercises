#include <stdio.h>
long soma_pa(int N, int r);

int main(void){
    int N;
    int A;
    int B;
    
    scanf("%d %d %d", &N, &A, &B);
    printf("%d, %d, %d\n", N, A, B);
    long soma = soma_pa(N, 1) - soma_pa(N, A) - soma_pa(N, B) + soma_pa(N, A*B);
    printf("%ld", soma);

    return 0;

}

//Sum the whole numbers in [1, N] if ratio is 1, else sum every number that is k*r, for any natural k, and less than N
long soma_pa(int N, int r){
    long soma;
    int sup = N - N % r;

    if(r != 1){
        soma = ((sup/r + 1)*sup)/2;
    }else{
        soma = (N*(1 + N))/2;
    }
    
    return soma;
}

