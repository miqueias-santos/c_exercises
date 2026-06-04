#ifndef BST_H
#define BST_H

#include <stdio.h>
#include <stdlib.h>

struct Node {
    struct Node *right, *left;
    int data;
};
typedef struct Node Node;

void insertNode(Node **ROOT, int value, int *no);
void insertNodeR(Node **ROOT, int value);
int preOrder(Node *ptr);
int inOrder(Node *ptr);
int menorElemento(Node *ptr); // Não eram necessárias, mas resolvi criar
int maiorElemento(Node *ptr);
void postOrder(Node *ptr);

#endif
