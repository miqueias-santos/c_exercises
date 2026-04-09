#include <stdlib.h>
#include <stdio.h>
int main()
{
    int *p = malloc(10 * sizeof(int)); // Alocação dinâmica. p aponta para uma região alocada
    printf("Endereço de p: %p\n", p);
    free(p); // A partir daqui, p é dangling pointer
    printf("Endereço de p após free: %p\n", p);
    //int a = *p; // modificar o endereço guardado por p após essa linha NÃO modifica a, pois a é uma varíavel de endereço distinto
    // Não seria possível criar uma variável de endereço p? Embora não haja necessidade, tendo um ponteiro para o endereço em questão

    int size_p; // Geralmente útil, até imprescindível, possuir o tamanho do vetor dinâmico. Permite determinar o tamanho do vetor em tempo de excecução.
    // Toda variável é difinida em tempo de compilação
    scanf("%d", &size_p);
    if(size_p < 10) size_p = 10;
    
    p = malloc(size_p * sizeof(int));
    if (p == NULL) return 1; // Condição de teste. Geralmente necessário. Alternativa: if(p = malloc(size_p * sizeof(int)) == NULL) 
    
    for (int i = 0; i < size_p; i++) {
        scanf("%d", p + i);
    }
    free(p);
    

    return 0;
}