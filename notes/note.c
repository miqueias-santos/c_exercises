#include <stdio.h>
int main(void){
    int matriz[3][3] = {{0, 1, 2}, {3, 4, 5}, {6, 7, 8}};
    int array[3] = {0, 1, 2};

    // if(matriz*3)  printf("Tem sentido") // Teste de tipo
    // Caso interessante, um erro mostra o tipo (warning do compilador), pois são resolvidos em tempo de execução.
    // Mostra exatamente que o nome, em expressão, análogo a array, decai para ponteiro, so que de array de j inteiros, para uma matriz[i][j]
    
    //Assim:
    /*
    -> Matriz + 1 é a linha i = 1, ainda ponteiro para array de 3 inteiros. Visto que: aritmética de ponteiros preserva o tipo; e pelo tipo, a um avanço de 3 inteiros
    -> Sobre passagem de função, esse decaimento explica o porquê de ser necessário informar o número de elementos de uma linha (número de colunas). Decai justamente para int(*)[3]
    -> Sobre dereferência: *(matriz + 1) == matriz[1] é sabido. Por essa igualdade, é possível dar sentido a dereferência de um int(*)[3] (ou int(*)[3])
    -> Qualitativamente, a deferência retorna um array de 3 inteiro (tipo int[3]), que em expressão, decai para int* 
    */
    
    // if((*matriz)*3)  printf("Tem sentido"); // Teste de tipo
    
    /* 
    -> Sobre endereço, a primeira ressalva interessante é: matriz + 1 (int(*)[3]) == *(matriz + 1)
    -> Bem mais sutil, e a primeira vista inexplicável: &matriz == matriz. Por quê?
    -> Note que, na mesma lógica, se int array[3];, &array == array
    -> O que isso indica? É um ponteiro que aponta (guarda) o próprio endereço. Não são ponteiros "comuns". O decaimento em ambos (e mais) tem essa peculiaridade. Analise.
    -> Isso cria uma espécie de comportamento encadeante: array(sendo do tipo int[3]) decai para int*, mas para endereçamento, &array é endereço do tipo int(*)[3] (não int**), ou seja, é um endereço de int[3] 
    */
 
    // if((&array)*3) printf("Tem sentido"); // Teste de tipo
    
    /*
    -> Informações assim importam nesse sentido. Daí então, &array torna-se o decaimento de uma matriz[i][3].
    -> Extendendo o conceito: &matriz é endereço do tipo int(*)[3][3] é o decaimento de algo do tipo int[k][3][3], correto?
    -> Para confirmar, deve-se olhar para memória: int[3] -> int* (aritmética de ponteiro tem lógica, junto com dereferência)
    -> int[3][3] -> int(*)[3] (aritmética de ponteiro ainda tem lógica - cada índice discreto somado faz retornar o próximo int[3] -, e deferência, mesmo que retornando um int[3], que decai, tem lógica)
    -> Agora veja: a informação ponteiro para "int[3]"" é imprescindível essencialmente para aritmética.
    -> Algo como int[3][3][3] (tome tempo para interpretar. Lido da esquerda para direita) -> int(*)[3][3], sendo necessário guardar os 2 tamanhos.
    -> Perceba que, essencialmente, são 3 matrizes 3 x 3. Decaindo para o ponteiro, a aritmética sentido, se sabidos os tamanhos. Para dereferência, novamente haverá outro decaimento: int[3][3] -> int(*)[3]
    -> A dereferência agora, sendo um ponteiro para int[3], faz sentido aritmético.
    -> Nesse termos, se generaliza. Notando que, ocorrento o decaimento, se perde a informação do número de "elementos a serem apontados". É mantido o tipo do apontandor, de maneira exata, para aritmética e futuras dereferências e decaimentos
    */

    //if((&matriz)*3) printf("Tem sentido"); // Teste de tipo
    
    /* PRÓXIMA DÚVIDA:
    
    int array1[3] = *matriz; // Por que isso não funciona
    int* array1 = *matriz; // Enquanto isso sim funciona
    
    */
  
    printf("%p\n", &matriz);
    printf("%p\n", matriz);    
    printf("%p\n", *matriz);    
    printf("%d\n", **matriz);    
    return 0;
}