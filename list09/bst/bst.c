#include "bst.h"

Node *newNode(int value) {
    Node *new = malloc(sizeof(Node));
    new->left = NULL;
    new->right = NULL;
    new->data = value;
    return new;
}

// Versão não recursiva
// NOTE: Node **ROOT na verdade é &ROOT, em parâmetro real, de um Node *ROOT
void insertNode(Node **ROOT, int value, int *no) {
    Node *new = newNode(value);
    if (new == NULL) { puts("Não foi possível inserir nó."); return; }
    (*no)++;

    if (*ROOT == NULL) *ROOT = new;
    else {
        Node *node = *ROOT;
        Node *next = *ROOT;

        while (next != NULL && node->data != value) {
            node = next;
            if (node->data > value) next = next->left;
            else if(node->data < value) next = next->right;
        }

        if (node->data > value) node->left = new;
        else if (node->data < value) node->right = new;
        else {
            free(new);
            (*no)--;
        }
    }
}

// Versão recursiva de InsertNode. Nessa versão, nós iguais são postos à esquerda.
void insertNodeR(Node **ROOT, int value) {
    Node **node = ROOT;
    if (*node == NULL) {
        *node = newNode(value); // leaf
        if (*node == NULL) puts("Não foi possível inserir nó.");
    }
    else {
        if ((*node)->data >= value) insertNodeR(&(*node)->left, value);
        else insertNodeR(&(*node)->right, value);
    }
}

// Processa primeiramente o nó, atravessa a esquerda e só então a direita. Apenas se diferenciam pela ordem de processamento.
// Retorna número de níveis da árvore. Caso ROOT == NULL, retorna -1.
int preOrder(Node *ptr) { // ROOT -> LEFT -> RIGHT
    int left_branch = 0;
    int right_branch = 0;

    if (ptr != NULL) {
        printf("%d ", ptr->data);
        if (!ptr->left && !ptr->right) return 1;

        left_branch += (preOrder(ptr->left) + 1);
        right_branch += (preOrder(ptr->right) + 1);

        if (left_branch >= right_branch) return left_branch;
        else return right_branch;

    }
    else return -1;
}

/* Atrevessa a árvore, assim como todas as travessias mostradas, priorizado a lado esquerdo. Atrevesa do ramo esquerdo até o fim,
só então processa o nó e atravessa a direita. Nota: atravessar a direita significar chamar a função novamente para o ramo direito, o que implica
percorrê-lo "a esquerda". */
// Retorna o número de folhas
int inOrder(Node *ptr) { // LEFT -> ROOT -> RIGHT
    int leafs = 0;
    if (ptr != NULL) {
        leafs += inOrder(ptr->left);

        printf("%d ", ptr->data);
        if (!ptr->left && !ptr->right) leafs++;

        leafs += inOrder(ptr->right);
    }
    return leafs;
}

// Atravessa a esquerda, depois a direita, então processa.
// Deleta a árvora.
void postOrder(Node *ptr) { // LEFT -> RIGHT -> ROOT
    if (ptr != NULL) {
        postOrder(ptr->left);
        postOrder(ptr->right);
        printf("%d ", ptr->data);
        free(ptr);
    }
}

// Retorna o menor elemento a bst. Se ROOT == NULL, retorna -1.
int menorElemento(Node *ptr) {
    if (ptr == NULL) return -1;
    else while (ptr->left != NULL) ptr = ptr->left;
    return ptr->data;
}

// Retorna o maior elemento a bst. Se ROOT == NULL, retorna -1.
int maiorElemento(Node *ptr) {
    if (ptr == NULL) return -1;
    else while (ptr->right != NULL) ptr = ptr->right;
    return ptr->data;
}
