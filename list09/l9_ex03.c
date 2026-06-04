#include "bst/bst.h"

int main() {
    // variáveis da bst
    Node *ROOT = NULL;
    int no = 0, num = 0, leafs = 0, niveis = 0, maior, menor;

    // cria a bst
    scanf("%d", &num);
    while(num != -1) {
        insertNode(&ROOT, num, &no);
        scanf("%d", &num);
    }
    if (no != 0) {
        maior = maiorElemento(ROOT);
        menor = menorElemento(ROOT);

        // outputs:

        // tinha como saber o número de níveis a partir de insertNode também, mas preferi usar uma função traverse
        fputs("PREORDEM: ", stdout); niveis = preOrder(ROOT); putc('\n', stdout);
        fputs("EMORDEM: ", stdout); leafs = inOrder(ROOT); putc('\n', stdout);
        fputs("POSORDEM: ", stdout); postOrder(ROOT); putc('\n', stdout); // deletou a árvore
        printf("NOS: %d\n", no);
        printf("FOLHAS: %d\n", leafs);
        printf("ALTURA: %d\n", no ? niveis - 1 : -1);
        printf("MENOR: %d\n", menor);
        printf("MAIOR: %d\n", maior);

    }
    else puts("ARVORE VAZIA");
}
