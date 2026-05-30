#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdlib.h>
#include <stdio.h>

struct Node {
    int value;
    struct Node *next;
};
typedef struct Node Node;

int IsEmptyList(Node *HEAD);

Node *NewNode(int value);

// Insere um node ao início da lista. Retorna 0 se foi possível, do contrário 1. Passível de alterar HEAD
int InsertAtBeginning(Node **AdrHEAD, int value);

// Insere um node em um índice especificado. Retorna 1 caso não seja possível, como index inválido, erro em alocação ou lista vazia
int Insert(Node **AdrHEAD, int index, int value);

// Insere elemento no fim da lista. Se lista for nula, ele inicia a lista alterado HEAD
int InsertAtEnd(Node **AdrHEAD, int value);

int RemoveAtBeginning(Node **AdrHEAD);

/*
int RemoveAtEnd(Node *HEAD) {
    if (HEAD == NULL) {

    }
    Node *node = HEAD;
    while(node->next != NULL)



    for (Node *node = HEAD; node != NULL; node = node->next)
}
*/
int Replace(Node *HEAD, int index, int value); // ?

void PrintList(Node *HEAD);

void DeleteList(Node **AdrHEAD);

#endif
