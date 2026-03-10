#include <stdio.h>
int main(void){
    int N, A, B;
    
    scanf("%d %d %d", &N, &A, &B);
    //printf("%d, %d, %d\n", N, A, B);
    long long somaN = (N + N*N)/2;
    long long supA = N - N % A; //último termo do intervalo que é k*A
    long long somaA = (supA * (supA/A + 1))/2;
    long long supB = N - N % B;
    long long somaB = (supB *(supB/B + 1))/2;
    long long supAB = N - N % (A*B);
    long long somaAB = (supAB *(supAB/(A*B) + 1))/2;
    long long soma = somaN - somaA - somaB + somaAB;
    printf("%lld\n", soma);
    if(soma % 2) printf("Opa xupenio AULAS...\n");
    else printf("Lá ele!!!\n");

    return 0;

}

