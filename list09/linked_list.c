#include "linked_list.h"
// Nota IMPORTANTE: Eu implementei esse código, mas fiz com int. Fiquei com preguiça de passar para char, então nas chamadas para função fiz cast para int

int IsEmptyList(Node *HEAD) {
    return (HEAD == NULL);
}

Node *NewNode(int value) {
    Node * new = malloc(sizeof(Node));
    if (new == NULL) printf("Erro ao alocar nó.\n");
    else new->value = value;
    return new;
}

// Insere um node ao início da lista. Retorna 0 se foi possível, do contrário 1. Passível de alterar HEAD
int InsertAtBeginning(Node **AdrHEAD, int value) {
    Node *new = NewNode(value);
    if (new == NULL) {
        printf("Erro ao inserir no início.\n");
        return 1;
    }

    new->next = *AdrHEAD;
    *AdrHEAD = new;
    return 0;
}

// Insere um node em um índice especificado. Retorna 1 caso não seja possível, como index inválido, erro em alocação ou lista vazia
int Insert(Node **AdrHEAD, int index, int value) {
    if (IsEmptyList(*AdrHEAD)) {
        printf("Lista vazia.\n");
        return 1;
    }
    else if(index < 0) {
        printf("Index inválido.\n");
        return 1;
    }

    Node *new = NewNode(value);
    if (new == NULL) {
        printf("Erro ao inserir.\n");
        return 1;
    }

    if (index == 0) {
        new->next = *AdrHEAD;
        *AdrHEAD = new;
    }
    else {
        Node *node = *AdrHEAD;
        for (int i = 0; i < index - 1; i++) {
            if (node == NULL) {
                printf("Index inválido.\n");
                free(new);
                return 1;
            }
            node = node->next;
        }

        new->next = node->next;
        node->next = new;
    }
    return 0;
}

// Insere elemento no fim da lista. Se lista for nula, ele inicia a lista alterado HEAD
int InsertAtEnd(Node **AdrHEAD, int value) {
    Node *new = NewNode(value);
    if (new == NULL) {
        printf("Erro ao inserir no fim.\n");
        return 1;
    }

    if (IsEmptyList(*AdrHEAD)) *AdrHEAD = new;
    else {
        Node *node = *AdrHEAD;
        while (node->next != NULL) node = node->next;
        node->next = new;
    }
    new->next = NULL;
    return 0;
}

int RemoveAtBeginning(Node **AdrHEAD) {
    if (IsEmptyList(*AdrHEAD)) {
        printf("Lista vazia.\n");
        return 1;
    }

    Node *aux = *AdrHEAD;
    *AdrHEAD = (*AdrHEAD)->next; // HEAD avança
    free(aux);
    return 0;
}
/*
int RemoveAtEnd(Node *HEAD) {
    if (HEAD == NULL) {

    }
    Node *node = HEAD;
    while(node->next != NULL)



    for (Node *node = HEAD; node != NULL; node = node->next)
}
*/
int Replace(Node *HEAD, int index, int value) { // ?
    Node *node = HEAD;
    int i = 0;

    while (i < index) {
        if (node == NULL) {
            printf("Index inválido.\n");
            return 1;
        }
        node = node->next;
        i++;
    }
    node->value = value;
    return 0;
}

void PrintList(Node *HEAD) {
    if (IsEmptyList(HEAD)) printf("Pilha vazia!\n");
    else {
        Node *node = HEAD;
        while(node != NULL) {
            printf("%c\n", (char)node->value);
            node = node->next;
        }
    }
}

void DeleteList(Node **AdrHEAD) {
    Node *delete = *AdrHEAD;
    Node *node = NULL;
    while(delete != NULL) {
        node = delete->next;
        free(delete);
        delete = node;
    }
    *AdrHEAD = NULL;
}
